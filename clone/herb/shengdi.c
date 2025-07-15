// shengdi.c

#include "herb.h"

void create()
{
	set_name(WHT "生地" NOR, ({ "shengdi", "herb_shengdi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 500);
        	set("weight", 60);
set("base_unit","块");
	}
	setup();
}
