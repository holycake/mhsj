// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("铜扣", ({"kouzi"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枚小铜扣");
                set("unit", "些");
                set("base_unit", "枚");
                set("base_weight", 40);
		set("base_value", 1);
        }
	set_amount(1);
        init_throwing(20);
        setup();
}

