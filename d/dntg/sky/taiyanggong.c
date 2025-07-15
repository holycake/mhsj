//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "太阳宫");
set("long", @LONG
    
LONG );


set("exits", ([
  "north"   : __DIR__"shenpinggong",
  "south"   : __DIR__"tonglugong",
  "west"   : __DIR__"huayuedian",
  "east"   : __DIR__"pixiangdian",
]));


set("objects", ([
]));



setup();
}
