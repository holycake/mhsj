// lengyue-baodao

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIW"冷月宝刀"NOR, ({ "lengyue dao", "blade" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", HIW"这是一把锋利的宝刀，刀柄上用金丝银丝镶着一钩眉毛月之形。\n"NOR);
		set("value", 100000);
		set("material", "steel");
		set("weapon/strength", 10);
		set("wield_msg", HIW "只见冷森森的一道青光激射而出。寒光闪烁不定,冷月宝刀已入$N的手里！\n" NOR);
		set("unwield_msg", HIW "「唰」的一声，寒光已不见。冷月宝刀被$N收入鞘中。\n" NOR);
	}
	init_blade(100);
	setup();
}
