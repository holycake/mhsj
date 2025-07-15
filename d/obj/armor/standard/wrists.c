// shoupi.c

#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("护腕", ({"wrists"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "副");
		set("armor_prop/armor", 1);
        }
        setup();
}

