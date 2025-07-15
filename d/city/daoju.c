inherit ROOM; 
#include <ansi.h>

int block_cmd(string);
void create ()
{
set ("short","道具店");
  set ("long", @LONG

这是全世界最有名的一家道具店，里面有许许多多
的珍宝，它们的好处只有等你去使用他才能知道。
LONG);
  set("exits", ([ /* sizeof() == 1 */
     "up" : __DIR__"kezhan",
]));
   set("chat_room",1);
  set("objects", 
([ // sizeof() == 2 */
  __DIR__"npc/dingdang" : 1,
]));
  set("no_time",1);

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
setup();
}

void init()
{
        object me = this_player();
        tell_room( environment(me), HIR"【"HIG"安全系统"HIR"】："HIR"热烈欢迎，"HIY + me->query("title") + " "
                + me->query("name") + "(" + me->query("id") + ")" +HIR " 来到"BLINK+HIC"魔幻世纪"NOR+HIR"道具店！\n"NOR);

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


