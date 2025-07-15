// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "掖门");

        set("long", @LONG

与山门外的掖门一样的硬山墙建筑，和八字墙搭配起来，虽然并不

高大，却也错落有致，下连马道，直通山门，马车可以直进此地，寺内

所需要的物资用品多从此处进入。    

LONG

        );

        set("exits", ([ 

  "north" : __DIR__"beilou",

  "southwest" : __DIR__"yonglu",

]));

        set("objects", ([

                __DIR__"obj/mache" : 1,

       ]) );

        set("outdoors", "shaolin");

	set("coor/x",-200);

	set("coor/y",190);

	set("coor/z",40);

	setup();

}

void reset()

{

object ob1,ob2, con;

::reset();

ob1 = new("/d/wanmei/obj/vege");

ob2 = new ("d/wanmei/obj/drywoods");

con = present("mache",this_object());

if(con && ob1 && ob2)

{

        ob2->set_amount(random(5)+1);

        ob1->move(con); ob2->move(con);

}

}

