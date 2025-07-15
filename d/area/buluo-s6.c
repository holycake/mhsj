#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short", HIR"←"NOR HIW" 空的村落  空的村落 "HIR"→  "NOR);
        set("long",@LONG 

这是一条遥远延伸的江湖大道，是每个江湖人都梦寐以求的一条路,
路的两边是每个江湖豪杰领袖建立帮会后天神为之修建的帮会村落。
江湖人,总是在人老之前心也就老了。曾经叱咤过的大江南北看过去
竟是一片沧茫,岁月剩下的除了那些曾经一起奋战朝夕的兄弟的影子
还在记忆中外，其他的就只是一颗曾经的江湖心了......

    *          *                     *          *
   ***        ***                   ***        ***
  **Y**      **Y**                 **Y**      **Y**
....|....  ....|....             ....|....  ....|....

LONG);

        set("exits", ([
                "south" : "/d/area/buluo-s7",
                  "north" : "/d/area/buluo-s5",
                  "west" : "/d/area/cunluo-w6",
                  "east" : "/d/area/cunluo-e6",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
}
