//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "宝光殿");
set("long", @LONG
    
LONG );


set("exits", ([
  "east"   : __DIR__"tongmingdian",
  "west"   : __DIR__"yunluw1",
]));


set("objects", ([
]));



setup();
}
