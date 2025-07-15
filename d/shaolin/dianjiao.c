// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "殿角楼");

        set("long", @LONG

只是一排山墙，排列着“清静”，“莲花”等法牌，仪仗和各类武

器。上下的石陛通过这个小山墙延伸到大雄宝殿。看去可见内额上题着

“宝树芳莲”，是玄烨的亲笔。

LONG

        );

        set("exits", ([ 

  "south" : __DIR__"tianwang",

  "northup" : __DIR__"daxiong",

  "east" : __DIR__"beilou",

  "west" : __DIR__"gulou",

]));

        set("objects", ([

                __DIR__"npc/monk_float" : 2,

       ]) );

	set("coor/x",-210);

	set("coor/y",200);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

