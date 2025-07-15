// bohe

#include "herb.h"

void create()
{
        set_name( HIC"薄荷" NOR, ({ "bo he", "herb_bohe" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("base_unit", "瓶");
                set("unit","瓶");
                set("value", 5000);
                set("weight", 50);
        }
        setup();
}
