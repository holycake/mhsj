// tianqi.c

#include "herb.h"

void create()
{
	set_name(WHT "田七" NOR, ({ "tianqi", "herb_tianqi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "根");
		set("value", 400);
        	set("weight", 55);
set("base_unit","根");
	}
	setup();
}
