// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

	object ob,con;

        set("short", "击鼓楼");

        set("long", @LONG

一间亭子似的建筑，中间一张牛皮巨鼓，相传是印度神牛皮制成，

几个僧人守在鼓旁，按时击鼓，一般都是暮鼓晨钟，日落时分你便可以

听到这悠扬的鼓声。

LONG

        );

        set("exits", ([ 

  "down" : __DIR__"gulou3",

]));

        set("objects", ([

                __DIR__"npc/monk5" : 3,

       ]) );

	set("coor/x",-220);

	set("coor/y",200);

	set("coor/z",70);

	set("outdoors","shaolin");

	setup();

	ob = new (__DIR__"obj/skin");

	con = new(__DIR__"obj/gu");

	if(ob && con) { ob->move(con); con->move(this_object());}

}

