// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "碑林");

        set("long", @LONG

这碑林最西，最为出名的当属“大唐天后御制诗书碑”，武则天撰

文，王知敬手书，碑身四龙盘顶，造型别致，碑文正书，笔力遒劲，古

来文武相通，到此的武学名家亦尝赞不绝口。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"bei2",

]));

        set("objects", ([

                __DIR__"obj/bei1" : 1,

		__DIR__"npc/pupil" :2,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-230);

	set("coor/y",180);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

