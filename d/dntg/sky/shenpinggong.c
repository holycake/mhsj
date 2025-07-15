//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "坤平宫");
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"taiyanggong",
  "north"   : __DIR__"qianyuangong",
]));


set("objects", ([
]));



setup();
}
