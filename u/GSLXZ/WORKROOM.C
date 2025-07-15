//By gslxz@mhsj  2001/3/17

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short",HIR"西瓜太郎"NOR+HIC"工作室"NOR);
        set ("long", @LONG
[1;33m
这里是系统管理员[2;37;0m[34m（[5m[1;31m天神[2;37;0m[34m）[1;33m为各级管理员工作学习而修建的工作室。
满目的清新的花草充满了整个的房间。[2;37;0m

[44;1m[1;34m ...。..。[2;37;0m[44;1m[37m[5m☆[2;37;0m[44;1m[1;34m.....。..。[5m★。[2;37;0m[44;1m[1;34m...。...。.....[5m[1;37m☆[2;37;0m[44;1m[1;34m........。。
。..[5m★[2;37;0m[44;1m[1;34m...[1;33m天籁妙，山水雅[2;37;0m[44;1m[1;34m.....。[5m[34m☆[2;37;0m[44;1m[1;34m..。。....[5m★[2;37;0m[44;1m[1;34m.....。...... 
...。。..[5m☆[2;37;0m[44;1m[1;34m..。..........。[5m[37m★[2;37;0m[44;1m[1;34m..。..[1;31m醉露为酒玉为花[44;1m[1;34m...[5m☆[2;37;0m[44;1m[1;34m....
...。..[5m[37m★[2;37;0m[44;1m[1;34m...[1;33m若人问我归何处[2;37;0m[44;1m[1;34m.。.[5m☆[2;37;0m[44;1m[1;34m.。...。..。..[5m[34m★[2;37;0m[44;1m[1;34m...。...。
。.......[5m☆[2;37;0m[44;1m[1;34m..。...。...[5m[37m★[2;37;0m[44;1m[1;34m.。....[1;31m彩云深处是我家[44;1m[1;34m.。[5m☆[2;37;0m[44;1m[1;34m......
[1;34m ...。..。[5m☆[2;37;0m[44;1m[1;34m.....。..。[5m★。[2;37;0m[44;1m [1;34m...。...。.....[5m[37m☆[2;37;0m[44;1m[1;34m........。。
[2;37;0m

LONG);
       set("item_desc" , ([ /* sizeof() == 1 */
"east": "房子里云雾缭绕，什么也看不清楚。\n",
"up": "房子里云雾缭绕，什么也看不清楚。\n",
"fy": "房子里云雾缭绕，什么也看不清楚。\n",
"yingke": "房子里云雾缭绕，什么也看不清楚。\n",
"silao": "房子里云雾缭绕，什么也看不清楚。\n",
]));
set("exits", 
        ([ //sizeof() == 3
                "kz" : "/d/city/kezhan",
             "down" : "/d/city/center",
                       "yingke": "/d/wiz/guest",
                       "silao": "/d/wiz/punish",
                       "fy" : "/d/wiz/courthouse",
                        "east" : "/u/zhongxin",
                      "up" : "/u/gslxz/workroom1", 
                ]));
            set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/iiiii_npc" : 1,
]));
  set("objects", ([
       "/u/iiiii/obj/computer" : 1,
       "/u/suannai/table" : 1,
       "/u/suannai/seat" : 1,
 //              "/u/gslxz/npc/dog" : 1,
           "/u/gslxz/obj/drink" : 1,
         "/u/gslxz/obj/jiank" : 1,
 ]));

        set("no_death", 1);
 set("no_fight", 1);
        set("no_kill", 1);
        set("no_time", 1);
        set("sleep_room", 1);

        set("no_clean_up", 0);
        setup();
      call_other("/obj/board/post_b", "???");
}

void init()
{
//        object me = this_player();
 //       tell_room( environment(me), CYN"主控电脑说道：请注意，" + me->query("title") + " "
  //              + me->query("name") + "(" + me->query("id") + ")" + " 来到了工作室！！！\n"NOR);
	object me = this_player();
	string id;

	id=(me->parse_command_id_list())[0];

if (getuid(this_player()) != "gslxz"
&& getuid(this_player()) != "songl") {
		tell_object(me, "咬死你！西瓜太郎的工作室你也敢闯。\n");
                tell_object(me, "我看你行 。  \n");
message("channel:gwiz",HIY+"〖"HIR"别墅警报"HIY"〗："NOR+HIR"据说有个坏蛋"HIY+me->name()+"("+me->query("id")+")"HIR"擅闯西瓜太郎的工作室，但是没有成功。\n"+NOR,users());               
                //          me->move("/d/city/menwc");
               	   if(this_player()->query("gender")=="男性")
                          me->move("/d/city/menwc");	   
else
                          me->move("/d/city/manwc");
   message_vision("$N似乎被人一脚踢了出来，神色有点狼狈。\n", me);
	}

}
/*
int valid_leave(object me, string dir)
{
              if(me->query("id")=="gslxz")
                return ::valid_leave(me, dir);
                 // temp access for future wiz.
                    if(me->query("id") != "gslxz")
                            return notify_fail(CYN"主控电脑"HIR"对你说道：咬死你！"HIG"西瓜太郎"HIR"的工作室你也敢乱闯，还是好好呆着吧。\n"NOR);
                            if( dir=="east" && !wizardp(me) 
                    || dir=="up" && !wizardp(me) 
                   || dir=="yingke" && !wizardp(me) 
              || dir=="silao" && !wizardp(me)           
                       || dir=="fy"
                     && !wizardp(me) ){
     return notify_fail(CYN"主控电脑"HIR"对你说道：咬死你！"HIG"西瓜太郎"HIR"的工作室你也敢乱闯，还是好好呆着吧。\n"NOR);
   }
                    return ::valid_leave(me, dir);
    }
*/
