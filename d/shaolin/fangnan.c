// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "方丈南院");

        set("long", @LONG

这里现在已经没有人住了，历代文人墨客，武学泰斗赠送方丈之物多存

放于此，其中尤以蔡京的“面壁塔额”最为出众。

LONG

        );

        set("exits", ([ 

  "southup" : __DIR__"changjing",

  "north" : __DIR__"fang",

]));

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",240);

	set("coor/z",40);

	setup();

}

void init()

{

	if(!this_player()->query_temp("see_fangzhang"))

	{

		set("exits/northup",__DIR__"lixue");

		delete("exits/north");

	}

	else 

	{

		set("exits/north", __DIR__"fang");

		delete("exits/northup");

	}

}

