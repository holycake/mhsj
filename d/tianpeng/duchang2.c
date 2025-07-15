//by mhsj@gslxz /2001/7/31
inherit ROOM;

int room_status = 0;
int *big = allocate(2);
int *res = allocate(2);

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

mapping gutous = ([ 
  "tc" : "[1;33m头彩[2;37;0m",
  "sd" : "[37m双对[2;37;0m",
  "qx" : "[1;31m七星[2;37;0m",
  "sx" : "[31m散星[2;37;0m",
 ]); 

void create()
{
  set ("short", "骨骰房");
  set ("long", @LONG

这里摆着一个八仙桌，中间摆着一个银盘。赌客们正聚精会神地下赌。
正席是一位胖子，手里不断玩弄着一对玉骰，他就是这里的招财。

墙上挂有一个匾，上面写着：
    [1;33m头彩[2;37;0m[33m（骰数由每次开盘前确定）      ：一赢三十六[2;37;0m
    [37m双对[33m（两骰号相同，且为偶数）      ：一赢十二[2;37;0m
    [1;31m七星[2;37;0m[33m（两骰之和为七）              ：一赢六[2;37;0m
[31m    散星[33m（两骰之和为三，五，九，十一）：一赢三[2;37;0m

匾角有一个牌子[1;31m(paizi)[2;37;0m。

LONG);

  set("item_desc",([
    "paizi" : "押[1;33m头彩骰[2;37;0m： gutou tc <amount> <money>\n"+ 
              "押[37m双对骰[2;37;0m： gutou sd <amount> <money>\n"+ 
              "押[1;31m七星骰[2;37;0m： gutou qx <amount> <money>\n"+ 
              "押[31m散星骰[2;37;0m： gutou sx <amount> <money>\n" 
  ])); 
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/zhuangd" : 1,
  ]));
  set("exits", ([ /* sizeof() == 1 */
      "westdown" : __DIR__"pianting",
  ]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_gutou","gutou");
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

int do_gutou (string arg)
{
  object me = this_player();
  string what;
  int amount;
  string money;
  object ob;

  if (! arg ||
      sscanf (arg,"%s %d %s",what,amount,money) != 3)
    return notify_fail("请使用： gutou <押骰种类> <数目> <货币>\n");

  if (what != "tc" &&
      what != "sd" &&
      what != "qx" &&
      what != "sx")
    return notify_fail("你要押什么骰？\n");

  ob = present (money+"_money", me);
  if (! ob)
    return notify_fail("你身上没有这种货币。\n");
  if (amount < 1)
    return notify_fail("请多押一些钱。\n");
  if (amount > ob->query_amount())
    return notify_fail("你身上的钱不够押。\n");

  if (me->query_temp ("gamble_gutou/amount") > 0)
    return notify_fail("你已经押过了。\n");

  if (room_status > 1)
    return notify_fail("现在正在赌呢，稍等片刻。\n");

  me->set_temp("gamble_gutou/kind",what);
  me->set_temp("gamble_gutou/amount",amount);
  me->set_temp("gamble_gutou/money",money);
  message_vision (sprintf("$N拿出%s%s%s，押在%s上。\n",
                          chinese_number(amount),
                          ob->query("base_unit"),
                          ob->query("name"),
                          gutous[what]),
                  me);
  if (amount == ob->query_amount())
    destruct (ob);
  else
    ob->add_amount(-amount);

  return 1;
}

int valid_leave(object me, string dir)
{
  if (dir == "westdown")
  {
    if (me->query_temp ("gamble_gutou/amount") > 0) 
      message_vision ("$N扔下押骰的钱。\n",me);
    me->delete_temp("gamble_gutou");
  }
  return ::valid_leave(me,dir);
}

void display_gutou (object room, int i)
{
  string str;
  switch (i)
  {
    case 1:
    {
      str = 
"[37m┌───┐[2;37;0m\n"+
"[37m│　　　│[2;37;0m\n"+
"[37m│　[1;31m●[2;37;0m[37m　│[2;37;0m\n"+
"[37m│　　　│[2;37;0m\n"+
"[37m└───┘[2;37;0m\n";

      break;
    } 
    case 2:
    {
      str = 
"[37m┌───┐[2;37;0m\n"+
"[37m│　　　│[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m│　　　│[2;37;0m\n"+
"[37m└───┘[2;37;0m\n";
      break;
    } 
    case 3:
    {
      str =
"[37m┌───┐[2;37;0m\n"+
"[37m│[1;31m●[2;37;0m[37m　　│[2;37;0m\n"+
"[37m│[1;31m　●[2;37;0m[37m　│[2;37;0m\n"+
"[37m│　[1;31m　●[2;37;0m[37m│[2;37;0m\n"+
"[37m└───┘[2;37;0m\n";
      break;
    } 
    case 4:
    {
      str = 
"[37m┌───┐[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m│　　　│[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m└───┘[2;37;0m\n";
      break;
    } 
    case 5:
    {
      str =
"[37m┌───┐[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m│[1;31m　●[2;37;0m[37m　│[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m└───┘[2;37;0m\n";
      break;
    } 
    case 6:
    {
      str = 
"[37m┌───┐[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m│[1;31m●　●[2;37;0m[37m│[2;37;0m\n"+
"[37m└───┘[2;37;0m\n";
      break;
    } 
  }
  tell_room (room,str);
}

int rdm()
{
  return random2(6)+1;
}

void gamble_prepare ()
{
  object room = this_object();
  tell_room (room,"招财唱道：新开盘！预叫头彩！\n");
  tell_room (room,"招财将两枚玉骰往银盘中一撒。\n");
  big[0] = rdm();
  big[1] = rdm();
  // keep two numbers different for a probability == 1/36
  while (big[0] == big[1])
  {
    reset_eval_cost();
    big[1] = rdm();
  }
  display_gutou (room,big[0]);
  display_gutou (room,big[1]);
  tell_room (room,"招财叫道：头彩骰号"+chinese_number(big[0])+
                  chinese_number(big[1])+"！\n");
  tell_room (room,"接着招财麻利地顺手将玉骰从盘中收回：现在开盘押钱！\n");
  room_status = 1;
  call_out ("gamble_start",24);
}
 
void gamble_start ()
{
  object room = this_object();
  tell_room (room,"招财喊声：封盘停押！\n");
  tell_room (room,"又补道：本盘头彩骰号是"+chinese_number(big[0])+
                  chinese_number(big[1])+"。\n");
  tell_room (room,"然后将两枚玉骰扔进两个金盅，一手持一盅摇将起来。\n");
  room_status = 2;
  call_out ("gamble_perform",6,0);
  call_out ("gamble_perform",12,1);
  call_out ("gamble_finish",18);
}

void gamble_perform (int i)
{
  object room = this_object();

  tell_room (room,"金盅倒扣在银盘上，玉骰滚了出来。\n");
  res[i] = rdm();
  display_gutou (room,res[i]);
}

void player_wins (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_gutou/money"));
  int amount = who->query_temp("gamble_gutou/amount");
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
  object money = new ("/obj/money/"+who->query_temp("gamble_gutou/money"));
  total = who->query_temp("gamble_gutou/amount");
  message_vision (sprintf("招财将$N押在银盘中的%s%s%s收走。\n",
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
  if (res[0]==big[0] && res[1]==big[1])
  {
    total = 36;
    win = "tc";
  }
  else if (res[0]==res[1] && (res[0]/2*2 == res[0]))
  {
    total = 12;
    win = "sd";
  }
  else 
  {
    int r = res[0]+res[1];
    if (r==7)
    {
      total = 6;
      win = "qx";
    }
    else if (r==3 || r==5 || r==9 || r==11) 
    {
      total = 3;
      win = "sx";
    }
    else
    {
      total = 0;
      win = "none of them";
    }
  }
  if (total == 0)
    tell_room (room,"招财叫道："+chinese_number(res[0])+
                    chinese_number(res[1])+"……空盘！\n");
  else
    tell_room (room,"招财叫道："+chinese_number(res[0])+
                    chinese_number(res[1])+"……"+gutous[win]+"！\n");
  i = sizeof(list);
  while (i--)
  {
    if (!userp(list[i]))
      continue;
    if (list[i]->query_temp("gamble_gutou/kind") == win)
      player_wins(list[i],total);
    else if (list[i]->query_temp("gamble_gutou/kind"))
      player_loses(list[i],total);
    list[i]->delete_temp("gamble_gutou");
  }
  tell_room (room,"\n");
  if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
  call_out ("gamble_prepare",5);
  else
  room_status=0;
}
