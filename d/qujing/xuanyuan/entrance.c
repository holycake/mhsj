// 古墓入口
#include <login.h>
#include <room.h>

inherit ROOM;
void create()
{
set("short","[32m入口[m");
set("long",@LONG

    你也不知道自己现在在什么地方，说是天上，可是自己刚才
是往地下转的，你不禁感动一种莫名的恐惧，如果没有胆量的话
，你还是回去为好，这里不是活人住的地方。

LONG);
set("exits", ([
         "up" : "/d/eastway/bingma",
         "enter" : __DIR__"road1",
]));
set("valid_startroom",1);
setup();

}

