inherit __DIR__"piggy.c";
#include <ansi.h>

void create()
{
    ::create();

      set ("short", "拱猪南房" );
    set("exits", ([
        "north": __DIR__"club3",
    ]) );
}
