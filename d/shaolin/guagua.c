// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "褂搭寮");

        set("long", @LONG

这是为同源的禅寺行者准备的住所，少林是禅宗祖庭，所以历来各

地拜山的行者不绝，所以特地辟出此地，供游方和尚使用，屋内陈设简

单，一张通铺极长，每铺上面一张小经桌。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"neiyuan",

  "east" : __DIR__"yibo",

]));

        set("objects", ([

                __DIR__"npc/other_monk" : 5,

       ]) );

	set("coor/x",-200);

	set("coor/y",300);

	set("coor/z",60);

	setup();

        replace_program(ROOM);

}

