// ercha.c

#include "herb.h"

void create()
{
        set_name(GRN "儿花" NOR, ({"erhua", "herb_erhua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "朵");
                set("value", 200);
                set("weight", 20);
set("base_unit","朵");
        }
        setup();
}
