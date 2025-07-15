#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("凤尾虾", ({"fengwei xia", "fengwei", "xia"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这家店自创的菜色，将青虾留尾壳上浆，配以青豆，冬菇丁，笋丁，葱白，\n然后用鸭油爆炒。肉白尾红，如艳丽的凤凰尾巴，赏心悦目\n");
		set("unit", "块");
		set("value", 30);
             
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
