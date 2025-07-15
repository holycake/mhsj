//Cracked by Roath
// mifan.c 米饭
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("米饭", ({"mifan"}));
	set_weight(240);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的肉包子。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 6);
		set("food_supply", 25);
	}
}
