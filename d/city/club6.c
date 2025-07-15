//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short","魔幻麻将屋");
        set ("long", @LONG

这里是魔幻世纪巫师为各位玩家提供的休闲场所,大家可以在这里打打麻将
牌来消磨时光。(ask wang about 麻将)
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"clubpoem",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                      "/d/city/npc/mj" : 1,

//                "/d/obj/misc/tables" : 1,
  //              "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

