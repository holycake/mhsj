// shexiang.c

#include "herb.h"

void create()
{
        set_name(YEL "麝香" NOR, ({ "she xiang", "herb_shexiang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "片");
                set("value", 2000);
                set("weight", 60);
set("base_unit","片");
        }
        setup();
}
