
inherit ROOM;

void create ()
{
        set ("short", "中药材铺");
        set ("long", @LONG

这是江州城中最大的一家中药材铺,这里面几乎包括了各个州郡，以
及名山大川所产的中药，门匾上几个大字灿金发亮，不时就有三五个
百姓模样，或习武之人进店买药。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "south": __DIR__"pingan-1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/obj/misc/tables" : 1,
                  "/d/jz/npc/zhang" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

