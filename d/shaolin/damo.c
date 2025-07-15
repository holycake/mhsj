// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "达摩院");

        set("long", @LONG

这里是达摩悟禅之处，院内陈设极为简单，四周墙壁密密麻麻挂满

了条幅，几个老僧须发皆白，正在埋首苦思，如中魔魇，一旦苦思有了

结果，便立刻挥笔书于条幅之上，大家印证。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"xiji",

  "west" : __DIR__"jiangwu",

  "north": __DIR__"cj",

  "south": __DIR__"luohan",

]));

        set("objects", ([

//                  __DIR__"npc/master_18" : 1,

//                  __DIR__"npc/laomonk" : 2,

       ]) );

	set("coor/x",-210);

	set("coor/y",350);

	set("coor/z",70);

	setup();

}

