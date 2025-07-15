// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "藏阁东廊");

        set("long", @LONG

红木长廊，上雕飞凤，美伦美焕，道路宽阔无比，路中有大锅一口

重一千一百斤，明代所铸，每顿所产，足够全寺食用，后少林日益蓬勃

此锅尚不能足，便放置于此，供游人赏玩。

LONG

        );

        set("exits", ([ 

  "westup" : __DIR__"changjing",

]));

        set("objects", ([

                __DIR__"obj/daguo" : 1,

       ]) );

	set("coor/x",-200);

	set("coor/y",230);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

