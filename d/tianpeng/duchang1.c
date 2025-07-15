//by mhsj@gslxz /2001/7/31
inherit ROOM;

int room_status = 0;
int *res = allocate(5);

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

mapping qians = ([ 
  "dqq" : "[1;33m大乾签[2;37;0m",
  "dkq" : "[37m大坤签[2;37;0m",
  "xqq" : "[1;35m小乾签[2;37;0m",
  "xkq" : "[35m小坤签[2;37;0m",
  "qq"  : "[1;31m乾签[2;37;0m",
  "kq"  : "[31m坤签[2;37;0m",
 ]); 

void create()
{
  set ("short", "押签房");
  set ("long", @LONG

一群人围着紫檀木大桌而坐，首席座着一位签房小童，正在一本正
经地从镶金黑盒里慢悠悠一根一根往外抽出乾坤签，码在桌面上。

墙上有一匾写着：
    [1;33m大乾签[2;37;0m[33m（全部五根皆为乾签）：一赢三十二[2;37;0m
    [37m大坤签[33m（全部五根皆为坤签）：一赢三十二[2;37;0m
    [1;35m小乾签[2;37;0m[33m（连续四根皆为乾签）：一赢十六[2;37;0m
    [35m小坤签[33m（连续四根皆为坤签）：一赢十六[2;37;0m
      [1;31m乾签[2;37;0m[33m（任意三根皆为乾签）：一赢二[2;37;0m
      [31m坤签[33m（任意三根皆为坤签）：一赢二[2;37;0m

匾角有一个牌子[1;31m(paizi)[2;37;0m。

LONG);

  set("item_desc",([
    "paizi" : "押[1;33m大乾签[2;37;0m： qian dqq <amount> <money>\n"+ 
              "押[37m大坤签[2;37;0m： qian dkq <amount> <money>\n"+ 
              "押[1;35m小乾签[2;37;0m： qian xqq <amount> <money>\n"+ 
              "押[35m小坤签[2;37;0m： qian xkq <amount> <money>\n"+ 
              "押[1;31m乾签[2;37;0m：   qian qq <amount> <money>\n"+ 
              "押[31m坤签[2;37;0m：   qian kq <amount> <money>\n",
  ])); 
  set("exits", ([ /* sizeof() == 1 */
      "eastdown" : __DIR__"pianting",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/qianke" : 1,
  ]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_qian","qian");
   add_action("do_quit","fly");
    add_action("do_quit","exit");

  add_action("do_quit","quit");  

  if (room_status > 0)
    return;

  remove_call_out ("gamble_prepare");
  remove_call_out ("gamble_start");
  remove_call_out ("gamble_perform");
  remove_call_out ("gamble_finish");
  call_out ("gamble_prepare",2);
  room_status = 1;
}
  int do_quit(string arg)
  {
  write(this_player()->query("name")+"[5m[31m，你干什么，用BUG莫，这里只可以赌博！[2;37;0m\n");
  return 1;
  }

int do_qian (string arg)
{
  object me = this_player();
  string what;
  int amount;
  string money;
  object ob;

  if (! arg ||
      sscanf (arg,"%s %d %s",what,amount,money) != 3)
    return notify_fail("[1;33m请使用：[41m qian <押签种类> <数目> <货币> [2;37;0m\n");

  if (what != "dqq" &&
      what != "dkq" &&
      what != "xqq" &&
      what != "xkq" &&
      what != "qq" &&
      what != "kq")
    return notify_fail("你要押什么签？\n");

  ob = present (money+"_money", me);
  if (! ob)
    return notify_fail("你身上没有这种货币。\n");
  if (amount < 1)
    return notify_fail("请多押一些钱。\n");
  if (amount > ob->query_amount())
    return notify_fail("你身上的钱不够押。\n");

  if (me->query_temp ("gamble_qian/amount") > 0)
    return notify_fail("你已经押过了。\n");

  if (room_status > 1)
    return notify_fail("现在正在赌呢，稍等片刻。\n");

  me->set_temp("gamble_qian/kind",what);
  me->set_temp("gamble_qian/amount",amount);
  me->set_temp("gamble_qian/money",money);
  message_vision (sprintf("$N拿出%s%s%s，押在%s上。\n",
                          chinese_number(amount),
                          ob->query("base_unit"),
                          ob->query("name"),
                          qians[what]),
                  me);
  if (amount == ob->query_amount())
    destruct (ob);
  else
    ob->add_amount(-amount);

  return 1;
}

int valid_leave(object me, string dir)
{
  if (dir == "eastdown")
  {
    if (me->query_temp ("gamble_qian/amount") > 0) 
      message_vision ("$N扔下押签的钱。\n",me);
    me->delete_temp("gamble_qian");
  }
  return ::valid_leave(me,dir);
}

void gamble_prepare ()
{
  object room = this_object();
  object *inv;
  int i;

  tell_room (room,"进宝将一大束签在桌上哗啦啦地迅速洗了一遍。\n");
  tell_room (room,"洗签之后，进宝啪地一声将签装入镶金黑盒，叫道：开押！\n");
  
  inv=all_inventory();
  i=sizeof(inv);
  while(i--) {
      if(userp(inv[i])) {
         room_status = 1;
         call_out ("gamble_start",25);
	 return;
      }
  }
  room_status=0;
  return;
}
 
void gamble_start ()
{
  object room = this_object();
  tell_room (room,"进宝喊声：停押！\n");
  tell_room (room,"然后闭上眼睛，将镶金黑盒打开从里开始往外抽签。\n");
  room_status = 2;
  call_out ("gamble_perform",3,0);
  call_out ("gamble_perform",6,1);
  call_out ("gamble_perform",9,2);
  call_out ("gamble_perform",12,3);
  call_out ("gamble_perform",15,4);
  call_out ("gamble_finish",18);
}

void gamble_perform (int i)
{
  object room = this_object();

  switch (random2(2))
  {
    case 0:
    {
      tell_room (room,"\n[33m□□  坤  签  □□[2;37;0m\n");
      res[i] = 0;
      break;
    }
    case 1:
    {
      tell_room (room,"\n[37m□□  乾  签  □□[2;37;0m\n");
      res[i] = 1;
      break;
    }
  }
}

void player_wins (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_qian/money"));
  int amount = who->query_temp("gamble_qian/amount");
  total = total * amount;
  money->set_amount(total);
  message_vision (sprintf("$N赢了%s%s%s！\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  money->move(who);
}

void player_loses (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_qian/money"));
  total = who->query_temp("gamble_qian/amount");
  message_vision (sprintf("进宝将$N押在盘中的%s%s%s收走。\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  destruct (money);
}

void gamble_finish ()
{
  string win;
  int total, i;
  object room = this_object();
  object *list = all_inventory(room);
  if (res[0]==1 && res[1]==1 && res[2]==1 && res[3]==1 && res[4]==1)
  {
    total = 32;
    win = "dqq";
  }
  else if (res[0]==0 && res[1]==0 && res[2]==0 && res[3]==0 && res[4]==0)
  {
    total = 32;
    win = "dkq";
  }
  else if ((res[0]==1 && res[1]==1 && res[2]==1 && res[3]==1) ||
           (res[1]==1 && res[2]==1 && res[3]==1 && res[4]==1))
  {
    total = 16;
    win = "xqq";
  }
  else if ((res[0]==0 && res[1]==0 && res[2]==0 && res[3]==0) ||
           (res[1]==0 && res[2]==0 && res[3]==0 && res[4]==0))
  {
    total = 16;
    win = "xkq";
  }
  else 
  {
    int r = 0;
    total = 2;
    for (i = 0; i < 5; i++)
      r += res[i];
    if (r >= 3)
      win = "qq";
    else
      win = "kq";
  }
  tell_room (room,"\n进宝睁开眼睛，迅速看一眼桌面，叫道："+qians[win]+"！\n");
  i = sizeof(list);
  while (i--)
  {
    if (!userp(list[i]))
      continue;
    if (list[i]->query_temp("gamble_qian/kind") == win)
      player_wins(list[i],total);
    else if (list[i]->query_temp("gamble_qian/kind"))
      player_loses(list[i],total);
    list[i]->delete_temp("gamble_qian");
  }
  tell_room (room,"\n");
  call_out ("gamble_prepare",5);
}
