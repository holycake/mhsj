// jinying.c

#include "herb.h"

void create()
{
        set_name(HIY "金银花" NOR, ({ "jinyin hua", "herb_jyhua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "朵");
                set("value", 300);
                set("weight", 50);
set("base_unit","颗");
        }
        setup();
}
