// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "僧兵院");

        set("long", @LONG

这是少林僧兵居所，到这里的都是少林精英，屋中陈设远胜和尚院，

上等竹席，青丝绸被，屋内张贴字画，每床前更有红木桌一张，屋中

更有几位少年僧人专职打扫。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"luohan",

  "east" : __DIR__"yaoku",

]));

	set("coor/x",-200);

	set("coor/y",340);

	set("coor/z",70);

	setup();

	create_door("east", "木门", "west", DOOR_CLOSED);

}

