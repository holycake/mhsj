//  An example non-weapon type of weapon

#include <weapon.h>
inherit RING;
void create()
{
	set_name("铁掌", ({ "ironfist" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个精铁打造的铁掌\n");
		set("value", 50);
		set("material", "steel");
	}
	init_ring(10);

	set("wield_msg", "$N从怀中摸出一个$n带在手上。\n");
	set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");

// The setup() is required.

	setup();
}
