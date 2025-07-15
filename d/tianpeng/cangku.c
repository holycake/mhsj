#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "储藏室");
  set ("long", @LONG

这里是天蓬府的储藏室，这里堆满了谷物
粮草。


LONG);

  set("exits", ([
                  "east" : __DIR__"zhulin9",
      ]));
  set("objects", ([
            __DIR__"obj/guzi"   : 2,
            __DIR__"obj/maizi"   : 2,
              __DIR__"obj/gangpa"   : 2,
      ]));

  setup();
}


