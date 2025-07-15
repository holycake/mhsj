// gancao.c

#include "herb.h"

void create()
{
        set_name( RED"甘草" NOR, ({ "gan cao", "herb_gancao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "颗");
                set("value", 500);
                set("weight", 60);
set("base_unit","颗");
        }
        setup();
}
