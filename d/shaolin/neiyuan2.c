// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "内院");

        set("long", @LONG

一个空旷的黄土院子。

LONG

        );

        set("exits", ([ 

  "north" : __DIR__"neiyuan3",

  "south" : __DIR__"neiyuan",

  "east" : __DIR__"heshang2",

  "west" : __DIR__"heshang",

]));

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",310);

	set("coor/z",60);

	setup();

        replace_program(ROOM);

}

