inherit ROOM; 
#include <ansi.h>

int block_cmd(string);
void create ()
{
set ("short","鞋帽店");
  set ("long", @LONG

这里的东西都相当不错，城里的太太小姐多来这里买衣服。逢年过节来
光顾的人就更多了。屋中横放一张七尺多长的柜台，柜台后的架子上是
一匹匹的布料和成衣。
LONG);
  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"zhuque-s3",
]));
   set("chat_room",1);
  set("objects", 
([ // sizeof() == 2 */
 __DIR__"npc/yao" : 1,
		__DIR__"npc/eryi" : 1,
]));
  set("no_time",1);

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
setup();
}
/*
void init()
{
        object me = this_player();
        tell_room( environment(me), HIY"欢迎," + me->query("title") + " "
                + me->query("name") + "(" + me->query("id") + ")" + " 光临道具店！！！\n"NOR);
   
}
*/
void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    if (verb == "bian") return 1; 
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;
}



