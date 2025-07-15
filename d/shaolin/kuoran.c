// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "廓然堂");

        set("long", @LONG

进门，抬头一块匾额“静中静”，这里四周无人，一般僧众绝不敢

进入，便是一般大和尚，也无权擅入，这里居住的都是寺外来拜会方丈

的绝世高人。屋中除了一桌一床，只有一红泥小火炉。

LONG

        );

        set("exits", ([ 

  "west" : __DIR__"fang",

]));

        set("objects", ([

                __DIR__"npc/baixiaoshen" : 1,

       ]) );

	set("coor/x",-200);

	set("coor/y",250);

	set("coor/z",40);

	setup();

        replace_program(ROOM);

}

