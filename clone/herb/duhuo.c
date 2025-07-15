// duhuo.c

#include "herb.h"

void create()
{
	set_name(HIB "独活" NOR, ({ "du huo", "herb_duhuo" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "根");
		set("value", 4000);
        	set("weight", 50);
	        set("base_unit","根");
	}
	setup();
}
