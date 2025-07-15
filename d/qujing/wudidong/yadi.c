//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "崖底");
        set("long", @LONG

白骨皑皑，磷火点点，不知有多少人丧生于此。

LONG
        );

        set("exits", ([
        ]));

        set("objects", ([
	"/d/city/npc/rat": 5,
        ]));

        setup();
}

