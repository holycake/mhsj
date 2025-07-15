//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "玄武殿");
set("long", @LONG
长梁雕龙，飞檐画凤。里面殿阁高大雄伟，层
层叠叠，琉璃瓦白玉掾富丽堂皇。    
LONG );


set("exits", ([
  "north"   : __DIR__"weiyuegong",
  "south"   : __DIR__"xuanyuantang",
]));


set("objects", ([
]));



setup();
}
