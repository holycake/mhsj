// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "碑林");

        set("long", @LONG

碑林从影壁直至天王殿，这里的碑多为外僧所立，最著名的当属日

僧邵元撰的“息庵禅师道行之碑”。益吉祥纂额，法然书丹。记述了名

僧息庵的生平，学佛之人当可效仿息庵所为，必能成一代大师。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"bei1",

  "southeast" : __DIR__"yingbi",

]));

        set("objects", ([

                __DIR__"obj/bei2" : 1,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-220);

	set("coor/y",180);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

