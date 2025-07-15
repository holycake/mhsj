// tugou.c

#include "herb.h"

void create()
{
	set_name(YEL "土狗" NOR, ({ "tu gou", "herb_tugou" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 900);
        	set("weight", 80);
set("base_unit","块");
	}
	setup();
}
