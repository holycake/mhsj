// blade.c

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("招魂皤", ({"zhaohun", "stick"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 300);
        }
        init_stick(15);
        setup();
}
