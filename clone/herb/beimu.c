// beimu.c

#include "herb.h"

void create()
{
        set_name(HIC "贝母" NOR, ({ "bei mu", "herb_beimu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "块");
                set("value", 7000);
		set("base_unit","块");
                set("weight", 100);
        }
        setup();
}
