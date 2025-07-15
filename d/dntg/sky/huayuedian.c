//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "华乐殿");
set("long", @LONG
    
LONG );


set("exits", ([
  "east"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
