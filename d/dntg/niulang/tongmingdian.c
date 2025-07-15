//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "通明殿");
set("long", @LONG
    
入宫的大道继续向前延伸，走不多远就是灵霄宝殿了。
在这里隐隐可以看见宝殿雄伟的殿门，和传说中神采
飞扬的天神们。
LONG );


set("exits", ([
  "north"   : __DIR__"bishagong",
  "south"   : __DIR__"caihongqiao2",
  "west"   : __DIR__"baoguangdian",
 "down"   : "/niulang/yinhe",
  "east"   : __DIR__"lingxudian",
]));


set("objects", ([
    __DIR__"npc/youshengzhenjun" : 1,
]));



setup();
}
