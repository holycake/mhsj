// jinying.c

#include "herb.h"

void create()
{
        set_name(HIY "单味金樱子" NOR, ({ "jinyingzi", "herb_jinyingzi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "颗");
                set("value", 300);
                set("weight", 50);
set("base_unit","颗");
        }
        setup();
}
