//Cracked by Roath
// piao.c 水瓢

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("水瓢", ({ "piao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把水瓢，不知道能乘多少水，不过当刀使，感觉可能不错。\n");
		set("value", 0);
		set("material", "wood");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(10);
	setup();
}
