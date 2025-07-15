// Room: /d/liwu/partyroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"周末party屋"NOR);
        set("long", @LONG
   这里是周末party屋，每个周末这里都会举行隆重的party，到时，每个来参加
party的人都可以拿到一份神秘的礼物，祝大家好运！
LONG
        );
        set("no_fight", 1);
        
         set("objects", ([
        "/d/liwu/obj/cabinet" : 1,
        ]));
        set("exits", ([
                "northeast" : __DIR__"happyjie",
        ]));

        setup();
        replace_program(ROOM);
}
