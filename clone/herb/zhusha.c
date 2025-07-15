// zhusha.c

#include "herb.h"

void create()
{
        set_name(RED "朱砂" NOR, ({ "zhu sha", "herb_zhusha" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "包");
                set("value", 400);
                set("weight", 30);
set("base_unit","包");
        }
        setup();
}
