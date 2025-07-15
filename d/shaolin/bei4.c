// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "碑林");

        set("long", @LONG

此碑大多数记述着少林武学，其中程绍题“少林观武”诗碑，清“

西来堂志善碑”都记述了少林武学的形神所在，习武之人到此无不注目

凝神，详细研究，以期领悟若干。过了东碑林，便是慈云堂。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"bei3",

  "east" : __DIR__"ciyun",

]));

        set("objects", ([

                __DIR__"obj/dabei" : 1,

                __DIR__"obj/unarmed" : 1,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-190);

	set("coor/y",180);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

