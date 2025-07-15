// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "山门殿角");

        set("long", @LONG

下接山道，上面便是少林正门，有细刻石狮一对，蹲在高大的须弥

雕花座上。给山门增添了一丝活力，石狮左右原来插有高大的旗杆，经

历了千年风雨，如今只剩下旗杆座内的夹杆石了。向上便是少林正门。

LONG

        );

        set("exits", ([ 

  "southdown" : __DIR__"ent3",

  "west" : __DIR__"shaoyang",

  "up"   : __DIR__"shanmen",

  "eastup" : __DIR__"ye1",

  "westup" : __DIR__"ye2",

]));

        set("objects", ([

                __DIR__"obj/stone" : 1,

		__DIR__"obj/lion" : 1,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",160);

	set("coor/z",30);

	setup();

        replace_program(ROOM);

}

