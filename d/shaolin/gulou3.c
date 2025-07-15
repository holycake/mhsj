// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "鼓楼");

        set("long", @LONG

这里往上便是打鼓楼，巨鼓便在上面。墙上的壁画

似乎里面饱含着至深的佛理。

LONG

        );

        set("exits", ([ 

  "up" : __DIR__"gulou4",

  "down" : __DIR__"gulou2",

]));

        set("objects", ([

                __DIR__"obj/bihua" : 1,

       ]) );

	set("coor/x",-220);

	set("coor/y",200);

	set("coor/z",60);

	setup();

        replace_program(ROOM);

}

