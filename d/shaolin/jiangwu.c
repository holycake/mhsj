// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "讲武堂");

        set("long", @LONG

这达摩院的的长老们传授武功的所在，达摩院的名师大多在此处讲习。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"damo",

]));

	set("coor/x",-220);

	set("coor/y",350);

	set("coor/z",70);

	setup();

        replace_program(ROOM);

}

