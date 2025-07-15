//changan city

inherit ROOM;

void create ()
{
        set ("short", "宠物店");
        set ("long", @LONG

这里是长安有名的宠物店，城里的太太小姐都喜欢来这里领养一些小猫，
小狗。也有一些成名的英雄来这里挑选自已的座骑。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"wangnan5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/petboss" : 1,
                  "/d/quest2/zhongkui" : 1,
	
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

