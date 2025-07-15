//穿山甲

#include "herb.h"

void create()
{
        set_name(RED "穿山甲" NOR, ({ "chuanshan jia", "herb_shanjia" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("value",5000);
                set("unit","包");
                set("base_unit", "包");
                set("base_value", 5000);
                set("base_weight", 50);
        }
        setup();
}
