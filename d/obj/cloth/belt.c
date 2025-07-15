#include <armor.h>

inherit WAIST;

void create()
{
        set_name("腰带", ({ "belt" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "leather");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

