// fuzi.c

#include "herb.h"

void create()
{
	set_name(WHT "附子" NOR, ({ "fu zi", "herb_fuzi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "粒");
		set("value", 200);
        	set("weight", 20);
set("base_unit","粒");
	}
	setup();
}
