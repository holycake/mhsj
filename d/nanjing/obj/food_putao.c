#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("葡萄", ({"grape", "putao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "高架金茎照水寒，累累小摘便堆盘。喜君不酿凉州酒，来救衰翁舌本乾。\n");
		set("unit", "颗");
		set("value", 0);
             
		set("food_remaining", 30);
		set("food_supply", 10);
	}
}
