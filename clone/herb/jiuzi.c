
#include "herb.h"

void create()
{
        set_name(HIY "九子" NOR, ({ "jiu zi", "jiuzi_hupo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "块");
                set("value", 900);
                set("weight", 20);
set("base_unit","块");
        }
        setup();
}
