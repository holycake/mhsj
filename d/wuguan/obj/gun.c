//Cracked by Roath
// weapon: tiegun.c
// Jay 3/18/96

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("铁棍", ({ "tiegun", "gun" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根浑铁棍，似乎威力不小。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_stick(20);
        setup();
}

