// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "禅定场");

        set("long", @LONG

这与修业场截然不同，无一丝声音，几个僧人在盘膝修行，佛家修

为讲的是清静无为，武学一道殊途同归，少林内功本就是由佛法而来，

所以禅定后而修行内功，可以事半功倍。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"jialan",

]));

        set("objects", ([

                __DIR__"npc/monk20a" : 2,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-220);

	set("coor/y",330);

	set("coor/z",70);

	setup();

        replace_program(ROOM);

}

