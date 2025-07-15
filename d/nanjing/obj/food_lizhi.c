#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("荔枝", ({"litchi", "lizhi"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "羅浮山下四時春，盧橘楊梅次第新。日啖荔枝三百顆，不辭長作嶺南人。\n");
		set("unit", "颗");
		set("value", 0);
             
		set("food_remaining", 10);
		set("food_supply", 10);
	}
}
