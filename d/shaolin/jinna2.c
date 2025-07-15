// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "紧那罗殿");

        set("long", @LONG

大雄殿东，内祀紧那罗像三尊，中为藤像，左为铜像，右为铁像，

造型皆雄奇。称为少林寺的护法伽蓝，这与别处奉关羽为护寺伽蓝大有

不同，所谓伽蓝，本身在梵语中便有寺院的意思。所以这间伽蓝殿的规

模实在不小。看着手持铁棍的紧那罗，你不禁心有所动。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"jinna",

]));

        set("objects", ([

                __DIR__"obj/jinna" : 1,

       ]) );

	set("coor/x",-190);

	set("coor/y",210);

	set("coor/z",40);

	setup();

        create_door("west", "木门", "east", DOOR_CLOSED);

}

