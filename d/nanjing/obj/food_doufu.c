#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烧豆腐", ({"doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "湖南小箱豆腐在沸水中氽过，捞出放鸡汤里，加上鸡肝、笋尖、虾仁，木耳点缀，\n烧出的豆腐，红是红，白是白，清爽柔润，鲜香扑鼻\n");
		set("unit", "块");
		set("value", 15);
             
		set("food_remaining", 2);
		set("food_supply", 50);
	}
}
