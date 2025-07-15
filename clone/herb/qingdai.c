// qingdai.c

#include "herb.h"

void create()
{
        set_name(HIC "青黛" NOR, ({ "qing dai", "herb_qingdai" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit","块");
                set("base_value", 1000);
                set("value",1000);
                set("base_weight", 100);
        }
        setup();
}
