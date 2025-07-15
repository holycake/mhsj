// xingren.c

#include "herb.h"

void create()
{
        set_name(HIY "杏仁" NOR, ({ "xingren", "herb_xingren" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "颗");
                set("value", 60);
                set("weight", 20);
set("base_unit","颗");
        }
        setup();
}
