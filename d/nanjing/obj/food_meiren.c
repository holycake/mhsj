#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("美人肝", ({"meiren gan", "meiren", "gan"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "鸭胰子配上鸡脯用鸭油爆炒。鲜嫩的鸭胰子白里泛红，流光溢彩，晶莹剔透。\n食之，鲜而嫩，脆而爽，回味悠然不尽。\n");
		set("unit", "块");
		set("value", 80);
             
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
