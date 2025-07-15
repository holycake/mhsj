// Room: /u/gslxz/workroom.c
#include <ansi.h>
inherit ROOM;
void create ()
{
    set ("short", HIW"风雪居"NOR);
  set ("long", @LONG

[44;1m[1;34m ...。..。[5m☆[2;37;0m[44;1m[1;34m.....。..。[5m★。[2;37;0m[44;1m[1;34m...。...。.....[5m☆[2;37;0m[44;1m[1;34m........。。
。..[5m★[2;37;0m[44;1m[1;34m...[1;33m天籁妙，山水雅[2;37;0m[44;1m[1;34m.....。[5m[34m☆[2;37;0m[44;1m[1;34m..。。....[5m★[2;37;0m[44;1m[1;34m.....。...... 
...。。..[5m☆[2;37;0m[44;1m[1;34m..。..........。[5m[34m★[2;37;0m[44;1m[1;34m..。..[1;31m醉露为酒玉为花[44;1m[1;34m...[5m☆[2;37;0m[44;1m[1;34m....
...。..[5m★[2;37;0m[44;1m[1;34m...[1;33m若人问我归何处[2;37;0m[44;1m[1;34m.。.[5m☆[2;37;0m[44;1m[1;34m.。...。..。..[5m[34m★[2;37;0m[44;1m[1;34m...。...。
。.......[5m☆[2;37;0m[44;1m[1;34m..。...。...[5m★[2;37;0m[44;1m[1;34m.。....[1;31m彩云深处是我家[44;1m[1;34m.。[5m☆[2;37;0m[44;1m[1;34m......
[1;34m ...。..。[5m☆[2;37;0m[44;1m[1;34m.....。..。[5m★。[2;37;0m[44;1m [1;34m...。...。.....[5m☆[2;37;0m[44;1m[1;34m........。。
[2;37;0m

这里是西瓜太郎的普通住宅，你看墙上的壁画多美丽呀，难怪[1;36m青云[2;37;0m总是要求住在
这里。
LONG);

     set("exits", ([
             "west" : __DIR__"bedroom",
               "down" : "/u/gslxz/workroom",
               "east" : __DIR__"guestroom",
             "out" : __DIR__"guardroom",
         "kz" : "/d/city/kezhan",
           "wiz" : "/d/wiz/wizroom",
             "guest" : "/d/wiz/guest",
     "hlym" : "/d/ourhome/honglou/kat",
]));    
  set("outdoors", 0);
 set("objects", ([
//                 "/u/gslxz/npc/baomu" : 1,
      ]));  
set("no_time", 1);
set("freeze", 1);
  set("no_fight", 1);
set("chat_room",1);
  set("no_magic", 1);
  set("no_upgrade_age",1);
  set("valid_startroom", 1);
 setup();
      call_other("/obj/board/gslxz_b", "???");
   }
/*
void init()
{
	object me=this_player(), env=environment(me);
	string id,*home_host,*home_guest;

	id=(me->parse_command_id_list())[0];
	home_host=env->query("home_host");
	home_guest=env->query("home_guest");

	if (member_array(id,home_host)==-1
	    && member_array(id,home_guest)==-1) {
		tell_object(me, "啊哈！ 闯进来了！\n");
                tell_object(me, "某某飞起一脚，正好踢中你的屁股 。  \n");
                tell_object(me, "某某飞起一脚，正好踢中你的屁股 。  \n");
//                me->move("/d/changan/phomes");
                me->move("/d/changan/phomes");
                message_vision("$N似乎被人一脚踢了出来，神色有点狼狈。\n", me);
	}
}
*/
void init()
{
	object me = this_player();
	string id;

	id=(me->parse_command_id_list())[0];

if (getuid(this_player()) != "gslxz"
  && getuid(this_player()) != "jojo"
  && getuid(this_player()) != "songl") {
		tell_object(me, "啊哈！ 闯进来了！\n");
                tell_object(me, "某某飞起一脚，正好踢中你的屁股 。  \n");
                tell_object(me, "某某飞起一脚，正好踢中你的屁股 。  \n");
message("channel:gwiz",HIY+"〖"HIR"别墅警报"HIY"〗："NOR+HIR"据说有个坏蛋"HIY+me->name()+"("+me->query("id")+")"HIR"擅闯西瓜太郎的工作室，但是没有成功。\n"+NOR,users());               
                //          me->move("/d/city/menwc");
               	   if(this_player()->query("gender")=="男性")
                          me->move("/d/city/menwc");	   
else
                          me->move("/d/city/manwc");
   message_vision("$N似乎被人一脚踢了出来，神色有点狼狈。\n", me);
	}
}
