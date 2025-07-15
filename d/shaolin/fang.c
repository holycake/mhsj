// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "方丈");

        set("long", @LONG

此乃寺中主持方丈的居所，前檐悬大钟一口，重达六百余斤，此室

当年乾隆曾住过，所以又称“龙庭”。

LONG

        );

        set("exits", ([ 

  "south" : __DIR__"fangnan",

  "northup" : __DIR__"lixue",

  "east" : __DIR__"kuoran",

  "west" : __DIR__"fangtui",

]));

        set("objects", ([

                __DIR__"npc/master_17_1" : 1,

       ]) );

	set("coor/x",-210);

	set("coor/y",250);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

