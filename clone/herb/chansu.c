// chansu.c

#include "herb.h"

void create()
{
        set_name(HIW "蟾酥" NOR, ({ "chansu", "herb_chansu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "朵");
                set("value", 1000);
                set("weight", 20);
		set("base_unit","块");
        }
        setup();
}
