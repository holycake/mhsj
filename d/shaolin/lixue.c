// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "立雪亭");

        set("long", @LONG

又称达摩亭，是当年二祖神光为求佛法，恭候达摩，雪没双膝的地方，

现在建了这座小小亭子，不必再受雪没双膝之苦。内有佛龛，有乾隆御

题“雪印明珠”，下有碑文记述二祖立雪断臂的故事。由此向北，便到

了后三殿。

LONG

        );

        set("exits", ([ 

  "northup" : __DIR__"lishi",

  "southdown" : __DIR__"fang",

  "west" : __DIR__"tayuan",

]));

        set("objects", ([

                __DIR__"obj/fuohe" : 1,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",260);

	set("coor/z",50);

	setup();

}

void init()

{

        if(!this_player()->query_temp("see_fangzhang"))

                set("exits/southdown", __DIR__"fangnan");

	else

		set("exits/southdown", __DIR__"fang");

}

