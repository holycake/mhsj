//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "棋香阁");
        set ("long", @LONG

这里是本站巫师为各位玩家提供的休闲场所。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
            //    "up" : __DIR__"clubup",
                "east" :"/d/wiz/entrance",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
//                "/d/obj/misc/tables" : 1,
              "/u/gslxz/obj/cch" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

