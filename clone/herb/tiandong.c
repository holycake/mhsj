// tiandong.c

#include "herb.h"

void create()
{
        set_name(HIC "天冬" NOR, ({ "tiandong", "herb_tiandong" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "根");
                set("value", 200);
                set("weight", 90);
set("base_unit","根");
        }
        setup();
}
