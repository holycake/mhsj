//Cracked by Roath
// choutou.c 锄头

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("锄头", ({ "chu tou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根粗重的锄头，你可能拿不起来，不知道到时候是用来锄草，还是锄菜。\n");
		set("value", 0);
		set("rigidity",50);
            set("material", "steel");
		set("wield_msg", "$N抡起一根$n抗在肩上。\n");
		set("unwield_msg", "$N将$n从肩上放了下来，差点砸住自己的脚。\n");
	}
  	init_staff(15);
	setup();
}
