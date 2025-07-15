// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "修业场");

        set("long", @LONG

这是少林弟子的修业场，实际上是练武场，地上是结实的硬土，本

该平坦，现在却凹凸不平，石锁，梅花桩，青砖一应俱全，僧人们分为

几群，或长棍，或大刀，各自苦练。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"jialan",

]));

        set("objects", ([

                __DIR__"npc/monk20" : 4,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-200);

	set("coor/y",330);

	set("coor/z",70);

	setup();

        replace_program(ROOM);

}

