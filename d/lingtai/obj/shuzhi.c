#include <weapon.h>

inherit STICK;

void create()
{
        set_name("树枝", ({"shuzhi"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material", "wood");
        }
        init_stick(10);
        setup();
}

