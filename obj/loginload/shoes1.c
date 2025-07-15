// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
	set_name(HIW "绣花小鞋" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一双小巧精致的绣花鞋。  \n");
		set("material", "cloth");
		set("unit", "双");
		set("armor_prop/armor", 5 );
		set("female_only", 1);
	}
	setup();
}

