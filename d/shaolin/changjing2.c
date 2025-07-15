// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

	object con,obj;

        set("short", "藏经阁");

        set("long", @LONG

这里有六只红木大柜，上书“大乘法宝”。

LONG

        );

        set("exits", ([ 

  "up"	: __DIR__"changjing3",

  "down" : __DIR__"changjing",

]));

        set("objects", ([

                __DIR__"obj/gui1" : 6,

		__DIR__"npc/monk6" : 2,

       ]) );

	set("coor/x",-210);

	set("coor/y",230);

	set("coor/z",60);

	setup();

        create_door("down", "木门", "up", DOOR_CLOSED);

	con = present("mugui" + sprintf(" %d",random(6)+1), this_object());

	if(con && obj = new(__DIR__"obj/yufe")) obj->move(con);

}

