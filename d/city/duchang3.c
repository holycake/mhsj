// Room: /d/changan/duchang3
// by snowcat 7/5/1997
inherit ROOM;

int room_status = 0;
object hg_ji = 0;
object lw_ji = 0;

mapping jis = ([ 
  "hg"  : "红冠鸡",
  "lw"  : "绿尾鸡",
 ]); 

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

void create()
{
  set ("short", "斗鸡房");
  set ("long", @LONG

斗鸡房里一左一右放着两个青竹鸡笼，一个鸡笼里关着一群红冠鸡，
另一个鸡笼里关着一群绿尾鸡。屋子正中是七尺见方的斗鸡场，由一
圈低低的青玉栏杆围成。一位白髯鸡仙正在张罗着斗鸡。在他的后面
墙上有一个牌子(paizi)。

LONG);

  set("item_desc",([
    "paizi" : "押红冠鸡： dou hg <amount> <money>\n"+ 
              "押绿尾鸡： dou lw <amount> <money>\n", 
  ])); 
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/jixian" : 1,
  ]));
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"clubup",
  ]));
  set("light_up", 1);
  set("no_fight", 1); // need no_fight, otherwise can use sth
  // like duandao. mon 10/16/98
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_dou","dou");
  add_action ("do_bian","bian");
  add_action ("do_fight","fight");
  add_action ("do_steal","steal");
  add_action ("do_kill","kill");
  add_action ("do_ji","ji");
  add_action ("do_cast","cast");
  add_action ("do_exert","exert");
  add_action ("do_perform","perform");
   add_action("do_quit","fly");
    add_action("do_quit","exit");

  add_action("do_quit","quit");  

  if (room_status > 0)
    return;

  remove_call_out ("gamble_prepare");
  remove_call_out ("gamble_start");
  remove_call_out ("gamble_perform");
  remove_call_out ("gamble_finish");
  call_out ("gamble_prepare",5);
  room_status = 1;
}
  int do_quit(string arg)
  {
  write(this_player()->query("name")+"，你干什么，用BUG莫，这里只可以赌博！\n");
  return 1;
  }

int do_dou (string arg)
{
  object me = this_player();
  string what;
  int amount;
  string money;
  object ob;

  if (! arg ||
      sscanf (arg,"%s %d %s",what,amount,money) != 3)
    return notify_fail("请使用： dou <押鸡种类> <数目> <货币>\n");

  if (what != "hg" &&
      what != "lw")
    return notify_fail("你要押什么样的鸡？\n");

  ob = present (money+"_money", me);
  if (! ob)
    return notify_fail("你身上没有这种货币。\n");
  if (amount < 1)
    return notify_fail("请多押一些钱。\n");
  if (amount > ob->query_amount())
    return notify_fail("你身上的钱不够押。\n");

  if (me->query_temp ("gamble_ji/amount") > 0)
    return notify_fail("你已经押过了。\n");

  if (room_status > 1)
    return notify_fail("现在正在斗鸡呢，稍等片刻。\n");

  if (room_status ==0)  {
	call_out("gamble_prepare",0);
	room_status = 1;
  }

  me->set_temp("gamble_ji/kind",what);
  me->set_temp("gamble_ji/amount",amount);
  me->set_temp("gamble_ji/money",money);
  message_vision (sprintf("$N拿出%s%s%s往青玉栏杆上一放，押在%s上。\n",
                          chinese_number(amount),
                          ob->query("base_unit"),
                          ob->query("name"),
                          jis[what]),
                  me);
  if (amount == ob->query_amount())
    destruct (ob);
  else
    ob->add_amount(-amount);

  return 1;
}

int valid_leave(object me, string dir)
{
  if (dir == "south")
  {
    if (me->query_temp ("gamble_ji/amount") > 0) 
      message_vision ("$N扔下押鸡的钱不要了。\n",me);
    me->delete_temp("gamble_ji");
  }
  return ::valid_leave(me,dir);
}

void gamble_prepare ()
{
  object room = this_object();
  tell_room (room,"白髯鸡仙从左右鸡笼里各拿出一只红冠鸡和一只绿尾鸡。\n");
  hg_ji = new(__DIR__+"npc/douji");
  hg_ji->set("name","红冠鸡");
  hg_ji->move(room);
  lw_ji = new(__DIR__+"npc/douji");
  lw_ji->set("name","绿尾鸡");
  lw_ji->move(room);
  tell_room (room,"白髯鸡仙说：好，可以押钱了，一赢二。\n");
  room_status = 1;
  call_out ("gamble_start",20);
}
 
void gamble_start ()
{
  object room = this_object();
  tell_room (room,"白髯鸡仙说声：停押，斗鸡。\n");
  tell_room (room,"然后将两只鸡抱起，拿出铁啄熟练地安上，把鸡放进栏内。\n");
  room_status = 2;
  set("no_fight",0); // allow chichen to kill. mon 10/16/98
  hg_ji->kill_ob(lw_ji);
  lw_ji->kill_ob(hg_ji);
  set("no_fight",1);
  call_out ("gamble_perform",1);
}

object present_ji (object room)
{
  object *list = all_inventory(room);
  int i;
  i = sizeof(list);
  while (i--)
  {
    if (userp(list[i]))
      continue;
    if (list[i]->id("ji"))
      return list[i];
  }
}

object present_ji2(object room)
{
	object *list = all_inventory(room);
	int i,j;

	i=sizeof(list);
	j=0;
	while(i--) {
		if(list[i]->id("ji")) {
			if(j==0) j=1;
			else return list[i];
		}
	}
}

void gamble_perform ()
{
  object room = this_object();
  object ji, ji2;

  if (! living(hg_ji))
    hg_ji->die();
  if (! living(lw_ji))
    lw_ji->die();

  ji = present_ji (room);
  if (ji && ji->is_fighting())
  {
    remove_call_out ("gamble_perform");
    call_out ("gamble_perform",1);
    return;
  }
  else if(ji) {
	ji2 = present_ji2(room);
	if(ji2) {
	        set("no_fight",0); // allow chichen to kill. mon 10/16/98
		ji->kill_ob(ji2);
		ji2->kill_ob(ji);
		set("no_fight",1); 
		remove_call_out ("gamble_perform");
    		call_out ("gamble_perform",1);
    		return;
	}
  }

  if (ji->query("kee")<15)
  {
    ji->unconcious();
    ji->die();
  }

  call_out ("gamble_finish",1);
  
}

void player_wins (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_ji/money"));
  int amount = who->query_temp("gamble_ji/amount");
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
  object money = new ("/obj/money/"+who->query_temp("gamble_ji/money"));
  total = who->query_temp("gamble_ji/amount");
  message_vision (sprintf("白髯鸡仙将$N留在玉栏上的%s%s%s收走。\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  destruct (money);
}

void clean_ji ()
{
  object room = this_object();
  object ji;
  ji = present_ji (room);
  if (ji)
  {
    tell_room (room,"白髯鸡仙将"+ji->query("name")+"递到屋内。\n");
    destruct (ji);
  }
  ji = present_ji (room);
  if (ji)
  {
    tell_room (room,"白髯鸡仙将"+ji->query("name")+"递到屋内。\n");
    destruct (ji);
  }
  ji = present("corpse",room);
  if (ji)
  {
    tell_room (room,"白髯鸡仙拎起"+ji->query("name")+"回头一扔。\n");
    destruct (ji);
  }
  ji = present("corpse",room);
  if (ji)
  {
    tell_room (room,"白髯鸡仙拎起"+ji->query("name")+"回头一扔。\n");
    destruct (ji);
  }
}

void gamble_finish ()
{
  string win;
  int total, i;
  object room = this_object();
  object ji = present_ji (room);
  object *list = all_inventory(room);
  if (! ji)
  {
    total = 0;
    win = "none of them";
  }
  else if (ji->query("name")=="红冠鸡")
  {
    total = 2;
    win = "hg";
  }
  else if (ji->query("name")=="绿尾鸡")
  {
    total = 2;
    win = "lw";
  }
  if (total > 0)
    tell_room (room,"白髯鸡仙说道："+jis[win]+"获胜！\n");
  else
    tell_room (room,"白髯鸡仙叹息道：双败陪本！\n");
  i = sizeof(list);
  while (i--)
  {
    if (!userp(list[i]))
      continue;
    if (list[i]->query_temp("gamble_ji/kind") == win)
      player_wins(list[i],total);
    else if (list[i]->query_temp("gamble_ji/kind"))
      player_loses(list[i],total);
    list[i]->delete_temp("gamble_ji");
  }
  tell_room (room,"\n");
  call_out ("clean_ji",1);
  if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
        call_out ("gamble_prepare",5);
  else
      room_status=0;
}

int do_bian (string arg)
{
  object who = this_player();
  object room = this_object();
  object ob;

  if (!arg)
    return 0;

  ob = present(arg,room);
  if (ob == hg_ji || ob == lw_ji)
  {
    message_vision ("$N头往鸡肚下一钻，想变成鸡。\n",who);
    message_vision ("白髯鸡仙对$N说道：是看鸡呢还是看你？\n",who);
    return 1;
  }
  return 0;
}

int do_fight (string arg)
{
  object who = this_player();
  object room = this_object();
  object ob;

  if (!arg)
    return 0;

  ob = present(arg,room);
  if (ob == hg_ji || ob == lw_ji)
  {
    message_vision ("$N向鸡提出挑战。\n",who);
    message_vision ("白髯鸡仙对$N说道：是看鸡斗鸡呢还是人斗鸡？\n",who);
    return 1;
  }
  return 0;
}

int do_steal (string arg)
{
  object who = this_player();

  message_vision ("$N偷偷摸摸地伸出手。\n",who);
  message_vision ("白髯鸡仙对$N说道：你真的要偷鸡摸狗不成？\n",who);
  return 1;
}

int do_kill (string arg)
{
  object who = this_player();
  object room = this_object();
  object ob;

  if (!arg)
    return 0;

  ob = present(arg,room);
  if (ob == hg_ji || ob == lw_ji)
  {
    message_vision ("$N恶狠狠地想杀鸡。\n",who);
    message_vision ("白髯鸡仙对$N说道：想吃鸡自个上馆子去。\n",who);
    return 1;
  }
  return 0;
}

int do_ji (string arg)
{
  object who = this_player();

  message_vision ("$N鸡头鸡脑地想要祭什么。\n",who);
  message_vision ("白髯鸡仙对$N说道：鸡又不是祖宗，对鸡祭什么祭。\n",who);
  return 1;
}

int do_cast (string arg)
{
  object who = this_player();

  message_vision ("$N鸡头鸡脑地念了几句咒语。\n",who);
  message_vision ("白髯鸡仙对$N说道：有鸡妨碍您施法您就出门去念吧。\n",who);
  return 1;
}

int do_exert (string arg)
{
  object who = this_player();

  message_vision ("$N想施内功。\n",who);
  message_vision ("白髯鸡仙对$N说道：别在这里练功，练出鸡胸怎办？\n",who);
  return 1;
}

int do_perform (string arg)
{
  object who = this_player();

  message_vision ("$N想施外功。\n",who);
  message_vision ("白髯鸡仙对$N说道：别在这里练功，练出鸡胸怎办？\n",who);
  return 1;
}
