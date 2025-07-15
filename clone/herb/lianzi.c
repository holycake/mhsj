// lianzi.c

#include "herb.h"

void create()
{
        set_name(HIG "莲子" NOR, ({ "lianzi", "herb_lianzi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "块");
                set("value", 600);
                set("weight", 20);
set("base_unit","块");
        }
        setup();
}
