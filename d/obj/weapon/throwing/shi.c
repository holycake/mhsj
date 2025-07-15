// dart.c

#include <weapon.h>

inherit THROWING;

void create()

{

        set_name("石块", ({"shi kuai", "shi", "stone"}));

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "些");

                set("base_unit", "块");

                set("base_weight", 50);

        }

        set_amount(random(10)+1);

        init_throwing(5);

        setup();

}

