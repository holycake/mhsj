#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("蛋烧卖", ({"dan shaomai", "shaomai"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用蛋皮裹以虾仁，成烧卖状，锅蒸熟后，浇上用鸡汁、菱粉、鸭油调成的卤汁。\n一笼色泽艳丽，小巧玲珑。\n");
		set("unit", "块");
		set("value", 16);
             
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
