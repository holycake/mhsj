
inherit ROOM;

void create()
{
        set("short", "床上");
        set("long", @LONG

LONG
        );
        
	set("exits", ([
                "out": "/d/changan/bx1",
            ]));

	set("sleep_room",1);
	set("if_bed",1);                             
       set("no_get_from",1);
       set("no_kill", 1);
       set("no_fight", 1);
   
        setup();
}


