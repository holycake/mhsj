// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "钟楼");

        set("long", @LONG

这里光线明亮，再往上的房间只有一层，四周无障，楼梯孤立。

LONG

        );

        set("exits", ([ 

  "up" : __DIR__"zhonglou6",

  "down" : __DIR__"zhonglou4",

]));

	set("coor/x",-190);

	set("coor/y",200);

	set("coor/z",80);

	setup();

        replace_program(ROOM);

}

