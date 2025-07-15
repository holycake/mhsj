// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "钟楼");

        set("long", @LONG

这里象似一间亭子四周空荡荡的，悬铁钟一口，重一万一千斤，铸于金

章宗太和年间，口沿八唇，上铸八卦，一旦敲响，直接九霄，响彻嵩巅。

LONG

        );

        set("exits", ([ 

  "down" : __DIR__"zhonglou5",

]));

        set("objects", ([

                __DIR__"obj/bigzhong" : 1,

       ]) );

	set("coor/x",-190);

	set("coor/y",200);

	set("coor/z",90);

	setup();

        replace_program(ROOM);

}

