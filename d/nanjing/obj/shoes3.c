// boots.c example shoes

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIR"红色皮靴"NOR, ({ "hongse xue", "shoes", "xie" }));

	set_weight(1000);
	if( clonep() )
	        set_default_object(__FILE__);
	else {
	        set("unit", "双");
	        set("value", 800);
	        set("material", "leather");

	        set("armor_type", "feet");
	        set("armor_prop/armor", 10);
	        set("armor_prop/personality", 1+random(2));
	        set("armor_prop/dodge", 60+random(20));
	        set("wear_msg","$N穿上一双$n。\n");
	        set("remove_msg","$N将$n脱了下来。\n");
	}

        setup();
}
int query_autoload() { return 1; }