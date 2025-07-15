// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "少阳桥");

        set("long", @LONG

古人云“翠岭回幽谷，清溪锁少林”，清溪指的便是少室溪，而开

锁的钥匙便是这少阳桥，也称少溪桥，石桥造型典雅，单孔石拱，正中

雕一龙首，栩栩如生。相传此处乃龙脉所在，少林呼吸之处，所以千年

来修缮不止。由桥西去是那一望无边的松林。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"shandan",

]));

        set("outdoors", "shaolin");

	set("coor/x",-220);

	set("coor/y",160);

	set("coor/z",30);

	setup();

        replace_program(ROOM);

}

