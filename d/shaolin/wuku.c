// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "武库");

        set("long", @LONG

这是少林武库，少林自从唐以来，便因为护唐王有功，所以可以自

拥僧兵，自造武器，历代帝王更常令名铸剑师落发少林，协助打造，所

以屋内琳琅满目，各色武器防具一应俱全。

LONG

        );

        set("exits", ([ 

  "east" : __DIR__"bingwest",

]));

	set("coor/x",-230);

	set("coor/y",340);

	set("coor/z",70);

	setup();

	create_door("east", "木门", "west", DOOR_CLOSED);

}

