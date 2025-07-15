// baishu.c

#include "herb.h"

void create()
{
        set_name(HIW "白术" NOR, ({ "baishu", "herb_baishu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit","根");
                set("base_unit", "根");
                set("value", 4000);
                set("base_weight", 100);
        }
        setup();
}
