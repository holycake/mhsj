// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "钟楼");

        set("long", @LONG

已经逐渐习惯了在这样的光线下看东西，地上青砖略微凹凸不平，

据说都是扫地僧门留下的，看来这里也是练功修行的好所在，四周墙壁

之上画满了壁画，只是年久，难以看清了。

LONG

        );

        set("exits", ([ 

  "up" : __DIR__"zhonglou3",

  "down" : __DIR__"zhonglou",

]));

        set("objects", ([

                __DIR__"obj/bihua2" : 1,

       ]) );

	set("coor/x",-190);

	set("coor/y",200);

	set("coor/z",50);

	setup();

        replace_program(ROOM);

}

