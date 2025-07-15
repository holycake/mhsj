inherit __DIR__"piggy.c";
#include <ansi.h>

void create()
{
    ::create();

    set ("short","拱猪北房");
    set("exits", ([
        "south": __DIR__"club3",
    ]) );
}
