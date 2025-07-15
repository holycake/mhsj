#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("杨梅", ({"strawberry", "yangmei"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "西凉葡萄，闽广荔枝，未若吴越杨梅。\n");
		set("unit", "颗");
		set("value", 0);
             
		set("food_remaining", 10);
		set("food_supply", 10);
	}
}
