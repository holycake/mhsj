// hugu.c

#include "herb.h"

void create()
{
        set_name(HIW "虎骨" NOR, ({ "hu gu", "hugu", "herb_hugu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "根");
                set("value", 900);
                set("weight", 100);
set("base_unit","根");
        }
        setup();
}
