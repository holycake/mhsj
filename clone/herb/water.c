// water.c

#include "herb.h"

void create()
{
        set_name(WHT "纯水" NOR, ({ "chun shui", "herb_chunshui" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是用来入药的纯水。\n");
                set("unit", "瓶");
                set("value", 10);
                set("weight", 50);
                set("no_drop",1);
set("base_unit","瓶");
        }
        setup();
}
