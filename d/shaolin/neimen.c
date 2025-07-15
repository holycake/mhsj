// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "内院门");

        set("long", @LONG

这是面并不高大的墙，闻得此门之后便是少林后院，

也就是天下武学的发源地--少林武院。

LONG

        );

        set("exits", ([ 

  "north" : __DIR__"neiyuan",

  "southup" : __DIR__"qianfe",

]));

        set("objects", ([

                __DIR__"npc/monk8" : 2,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",290);

	set("coor/z",60);

	setup();

}

int valid_leave(object me, string dir)

{

        object ob;

if( userp(me) &&

dir=="north" && ob=present("shaolin monk", this_object()) &&

me->query("class") != "shaolin")

return notify_fail(

"和尚说道：只有少林寺弟子才可以进入少林内院。\n");

return 1;

}

