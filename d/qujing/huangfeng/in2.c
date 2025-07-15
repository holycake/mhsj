//Cracked by Roath

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

正前方是一个高台，黄风怪平时都是在那个地方发号施令，
这也是无数小妖精梦想的事情，有朝一日自己也能修仙得
道。
LONG);

  set("exits", ([
        "north"   : __DIR__"in3",
        "south": __DIR__"in1",
      ]));
      set("objects",([
        __DIR__"npc/yaojing.c":2,
      ]));
  setup();
}
void init()
{	object obj;
        object ob = this_player();
	string dan= "dingfeng dan";
	
       if (! ob->query_temp("apply/name") 
	||ob->query_temp("apply/name")[0] != "[31m花脚蚊子[m"
	||!objectp(obj = present(dan, ob)))
        {
		
        message_vision(HIY"忽然黄风怪大喊一声：怎么没见过这个人！\n"NOR,ob);
        message_vision(HIY"只见黄风怪大嘴一鼓，吹起了三昧神风。\n"NOR,ob);
        message_vision(HIY"只见$N如狂风中的风沙一样飞上了天空。\n"NOR,ob);
        ob->apply_condition("eyeill",50);
	ob->unconcious();
	ob->set_temp("winded",1);
	
	if( ob->query_temp("lingji1_done") == "yes" )
	{
	ob->move("/d/qujing/huangfeng/shanlu2");
        return;
	}
	ob->move("/d/qujing/huangfeng/shanlu2new");
	}
        return;
}
