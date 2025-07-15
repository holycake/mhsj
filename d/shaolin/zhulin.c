// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "竹林");

        set("long", @LONG

一片竹林，伴随阵阵山风，竹叶的婆娑之声恰似丝竹之音，沁人心

脾，阳光虽烈，这里却清幽异常，一眼望去，竟然看不见尽头。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"diyuan",

  "west" : __DIR__"yinshi",

]));

        set("outdoors", "shaolin");

	set("coor/x",-240);

	set("coor/y",380);

	set("coor/z",70);

	setup();

        replace_program(ROOM);

}

