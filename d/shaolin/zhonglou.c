// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "钟楼");

        set("long", @LONG

进得这里，光线突然暗了下来，只有幽幽的烛光在闪烁着，

屋角一块铜碑，立有“铸造铜弥勒碑记”。

LONG

        );

        set("exits", ([ 

  "up" : __DIR__"zhonglou2",

  "west" : __DIR__"beilou",

]));

        set("objects", ([

                __DIR__"obj/tong" : 1,

       ]) );

	set("coor/x",-190);

	set("coor/y",200);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

