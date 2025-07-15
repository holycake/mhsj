inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("名贵补品" , ({ "good food", "food" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  set("long", WHT
      "用各种名贵药材炖成的补品\n" NOR);
		set("unit", "碗");
		set("value", 2000);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
	object me;
	int max_gin, max_kee, max_sen;
	me = this_player();
	max_gin = (int) me->query("max_gin");
        max_kee = (int) me->query("max_kee");
        max_sen = (int) me->query("max_sen");
	message_vision( HIR "$N的全身映出一阵红光！！\n" NOR, me);
	max_gin = max_gin * 11/10;
	max_kee = max_kee * 11/10;
	max_sen = max_sen * 11/10;
	switch(random(3)){
		case 0:
			me->set("max_gin", max_gin);
			break;
		case 1:
			me->set("max_kee", max_kee);
			break;
		case 2:
			me->set("max_sen", max_sen);
			break;
			}
	destruct(this_object());
        return 1;
}
