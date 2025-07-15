//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "乾元宫");
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"shenpinggong",
  "north"   : __DIR__"lingxiao",
]));


set("objects", ([
]));



setup();
}
