// xuejie.c

#include "herb.h"

void create()
{
	set_name(RED "血竭" NOR, ({ "xuejie", "herb_xuejie" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 200);
        	set("weight", 40);
set("base_unit","块");
	}
	setup();
}
