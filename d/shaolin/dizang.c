// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "地藏殿");

        set("long", @LONG

殿内昏暗，因为供奉的是幽冥教主，殿中一座铜铸地藏像，左右两

侍者，座下是谛听神兽。四周墙上壁画难以辨认，似乎是经脉图，但是

边上歪曲的文字弄不明白。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"qianfe",

]));

        set("objects", ([

                __DIR__"obj/herb" : 1,

       ]) );

	set("coor/x",-220);

	set("coor/y",280);

	set("coor/z",70);

	setup();

	create_door("east", "木门", "west", DOOR_CLOSED);

}

