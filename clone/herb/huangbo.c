// huangbo.c

#include "herb.h"

void create()
{
        set_name(YEL "黄柏" NOR, ({ "huang bo", "herb_huangbo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "包");
                set("value", 1000);
                set("weight", 50);
set("base_unit","包");
        }
        setup();
}
