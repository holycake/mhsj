// shoupi.c

#include <armor.h>

inherit HANDS;

void create()
{
        set_name("手套", ({"hands"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "副");
		set("armor_prop/armor", 1);
        }
        setup();
}

