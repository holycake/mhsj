//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "天宫城墙");
set("long", @LONG
    
高大雄伟的天宫城墙，上面铺满琉璃瓦，沿着
宫墙走去，三步一岗，五步一哨。戒备森严。
LONG );


set("exits", ([
  "south"   : __DIR__"dongtian",
  "north"   : __DIR__"tgqe6",
]));


set("objects", ([
    __DIR__"npc/tianding3" : 1,
]));



set("outdoors", 1);

setup();
}
