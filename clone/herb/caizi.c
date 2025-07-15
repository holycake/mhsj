// caizi.c

#include "herb.h"

void create()
{
        set_name(HIW "白花菜子" NOR, ({ "baihua caizi", "caizi", "herb_caizi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "根");
                set("value", 500);
                set("weight", 100);
                set("base_unit","根");
        }
        setup();
}
