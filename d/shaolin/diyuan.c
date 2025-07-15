// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "邸园精舍");

        set("long", @LONG

邸园精舍是天竺巨富以黄金铺地，买来送与佛祖说法的花园，可见

其精美和宝贵，这里的邸园比起天竺邸园精舍只怕也不遑多让，摇曳的

竹影和着池塘中粉色的睡莲，浅吟的黄莺飞向落日前的彩霞，一阵檀香

的气味更让人心中一片清静。环顾四周，南北各有一小楼。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"shan",

  "west" : __DIR__"zhulin",

  "north" : __DIR__"qingjing",

  "south" : __DIR__"wuwei",

]));

        set("objects", ([

                __DIR__"npc/zauron" : 1,

       ]) );

	set("coor/x",-230);

	set("coor/y",380);

	set("coor/z",70);

	setup();

        replace_program(ROOM);

}

