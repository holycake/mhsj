// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "鼓楼");

        set("long", @LONG

上楼来，房屋略小，可依旧高大无比，四周有古碑陈列其中，其中

一幅“达摩一苇渡江图”特别精彩，达摩所折之苇，皆一花五叶，象征

禅宗一脉单传，分为五派。

LONG

        );

        set("exits", ([ 

  "up" : __DIR__"gulou3",

  "down" : __DIR__"gulou",

]));

        set("objects", ([

                __DIR__"npc/monk3" : 1,

       ]) );

	set("coor/x",-220);

	set("coor/y",200);

	set("coor/z",50);

	setup();

        replace_program(ROOM);

}

