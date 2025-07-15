// /u/gslxz/workroom

inherit ROOM;

void create()
{
        set("short", "床上");
        set("long", @LONG
　　　　　　～～～～～～～
　　　　　　　～　～　　  ～　～
            ～　～　  ⊙　  ～　～
　　　　　　　～　～　 　 ～　～
　　　　　　　　～～～～～～～
LONG
        );
        
	set("exits", ([
                "out": "/u/gslxz/bedroom",
            ]));
	set("sleep_room",1);
	set("if_bed",1);                             
       set("no_time", 1);
set("freeze", 1);
  set("no_fight", 1);
set("chat_room",1);
  set("no_magic", 1);
  set("no_upgrade_age",1);
  set("valid_startroom", 1);          
        setup();
}



