#include <armor.h>

inherit HANDS;

void create()
{
        set_name("手套", ({ "gloves" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

