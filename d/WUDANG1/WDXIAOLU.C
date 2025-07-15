// Room: /d/wudang/wdxiaolu
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "小路" NOR);
        set("long", @LONG
一条通往武当的小路，由于这条路土匪经常出没，加上路不太好走，
所以人烟稀少，很没有人走。

LONG
        );
        set("exits", ([
//  "north" : "/d/changan/wdxiaolu4",
  "south" : __DIR__"wdxiaolu1",
]));

        set("no_clean_up", 0);
        set("outdoors", "wudang");

        setup();
        replace_program(ROOM);
}

