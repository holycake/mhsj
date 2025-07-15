
inherit ROOM;

void create ()
{
        set ("short", "罗汉塔");
        set ("long", @LONG


                        佛


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
//                "east" : __DIR__"wailiu2",
        ]));

/*        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shouchen" : 1,
     __DIR__"npc/xiushi" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");*/
   set("no_clean_up", 0);
   set("no_fight", 1);        
        setup();
   replace_program(ROOM);
}



