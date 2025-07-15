#include <ansi.h>

inherit ROOM;
void create ()
{
      set ("short", HBMAG+HIY" 翠竹亭 "NOR);
  set ("long", @LONG

          [1;32m  翠   竹   亭   [2;37;0m

这里是由翠竹做成的亭子，这里别具一格，
高老庄的三小姐翠兰，经常坐在这里的竹椅
上游览竹林中的景色。

LONG);

  set("exits", ([
              "out" : __DIR__"zhulin7",
      ]));
  set("objects", ([
        __DIR__"npc/lan"   : 1,
        __DIR__"npc/cui"   : 1,
      ]));

  setup();
}


