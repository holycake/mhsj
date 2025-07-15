// yanghuo.c

#include "herb.h"

void create()
{
        set_name(GRN"恙活" NOR, ({ "yanghuo", "herb_yanghuo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "块");
                set("value", 200);
                set("weight", 40);
set("base_unit","块");
        }
        setup();
}
