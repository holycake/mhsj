//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;
#include #include "jiandi.h"

void create ()
{
  set ("short", "[1m涧底[m");
  set ("long", @LONG

涧底到处都是些水草，还有些小虾米，鱼儿穿来穿去，偶尔还能看到
一两具骸骨，看来都是白龙吃剩的骨头。

LONG);

  set("exits", ([
        "north" : __DIR__"jiandi4",
        "west"  : __DIR__"jiandi2",
      ]));
   set("objects", ([
        "/d/jz/obj/fish": 3,
        ]));
  setup();

}
