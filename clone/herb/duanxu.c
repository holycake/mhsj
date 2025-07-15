// zihua.c

#include "herb.h"

void create()
{
        set_name(HIC "断续" NOR, ({ "duanxu", "herb_duanxu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "朵");
                set("value", 500);
                set("weight", 20);
set("base_unit","朵");
        }
        setup();
}
