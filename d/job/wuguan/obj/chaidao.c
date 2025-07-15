//Cracked by Roath
// chaidao.c   柴刀
//by yfengf

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("柴刀", ({ "chai dao", "dao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);
		set("material", "iron");
		set("long", "这是一柄柴刀，刀刃上还有几个豁口，看来十分旧了。\n");
		set("wield_msg", "$N抽出一把柴刀的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n别到腰间。\n");
	}
	init_blade(10);
	setup();
}
