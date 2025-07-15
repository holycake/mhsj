#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "竹林");
  set ("long", @LONG

这里尽是些参天竹子，你一走进来，就迷失了方
向，只觉得四周只是一片墨绿，周围景色都是一
样的。

LONG);

  set("exits", ([
              "east" : __DIR__"zhulin2",
              "north" : __DIR__"zhulin4",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}


