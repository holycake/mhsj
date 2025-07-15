// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "甘露台");

        set("long", @LONG

据说跋陀译经，天降甘露，所以名为甘露台，台顶两株古柏，台下

几棵古树，把甘露台团团包住。

LONG

        );

        set("exits", ([ 

  "eastdown" : __DIR__"tayuan",

]));

        set("objects", ([

                __DIR__"npc/master_21" : 1,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-230);

	set("coor/y",260);

	set("coor/z",60);

	setup();

	create_door("eastdown", "木门", "westup", DOOR_CLOSED);

}

