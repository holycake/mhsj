// lianqiao

#include "herb.h"

void create()
{
        set_name( HIY"连翘" NOR, ({ "lian qiao", "herb_lianqiao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "包");
                set("value", 500);
                set("weight", 50);
set("base_unit","包");
        }
        setup();
}
