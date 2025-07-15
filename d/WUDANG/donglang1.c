// donglang1.c 东厢走廊
//lpg 19991005

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "东厢走廊");
        set("long", @LONG
你走在一条走廊上，东边有几间雅室，人来人往很热闹。西边是大殿。
LONG );
        set("exits", ([
                "west" : __DIR__"sanqingdian",
        ]));
        setup();
}
