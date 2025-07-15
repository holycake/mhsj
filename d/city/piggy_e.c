inherit __DIR__"piggy_two.c";
#include <ansi.h>

void create()
{
    ::create();

      set ("short", "双人拱猪房" );
    set("exits", ([
        "west": __DIR__"club3",
    ]) );
}
