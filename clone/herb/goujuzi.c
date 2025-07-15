// goujuzi.c

#include "herb.h"

void create()
{
        set_name( HIY"苟枸子" NOR, ({ "goujuzi", "herb_juzi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "根");
                set("value", 300);
                set("weight", 50);
set("base_unit","根");
        }
        setup();
}
