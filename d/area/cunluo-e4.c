#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short", HIW"空的村落"NOR);
        set("long", 

HBBLU HIW"\n                                                                     \n"NOR
HBBLU HIW"                                                                     \n"NOR
HBBLU HIW"                                                                     \n"NOR
HBBLU HIW"                                                                     \n" NOR
HBBLU HIW"                                                                     \n"NOR
HBBLU HIW"                                                                     \n"NOR   
HBBLU HIW"                                                                     \n" NOR   
HBBLU"                                                                     \n\n" NOR  

);

        set("exits", ([
                "west" : "/d/area/buluo-s4",
//                  "east" : "/d/area/",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
}
