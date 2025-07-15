#include <ansi.h>
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("松鼠鳜鱼", ({"songshu guiyu", "guiyu", "fish", "yu", "songshu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "松鼠鳜鱼是著名传统苏菜。以鳜鱼去骨、剖花、炸制，呈松鼠状，再浇上糖醋卤汁而成。该菜口感鲜甜、脆嫩。\n");
		set("unit", "块");
		set("value", 160);
             
		set("food_remaining", 10);
		set("food_supply", 50);
	}
}
