// huajiao.c

#include "herb.h"

void create()
{
        set_name(YEL "川花椒" NOR, ({ "chuan huajiao", "huajiao", "herb_huajiao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "根");
                set("value", 400);
                set("weight", 100);
set("base_unit","根");
        }
        setup();
}
