// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "慈云堂");

        set("long", @LONG

当年为慈云庵，为女香客所备，后少林立规后，也就荒废了，后来

许多石碑干脆放在这里了。其中董其昌的“道公碑铭”当属一绝。这里

有若干僧众出售碑文拓本，供人研究。四行碑文，大多有售。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"bei4",

]));

        set("objects", ([

                __DIR__"npc/bookmonk" : 1,

       ]) );

	set("coor/x",-180);

	set("coor/y",180);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

