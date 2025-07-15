// guiwei.c

#include "herb.h"

void create()
{
	set_name(WHT "归尾" NOR, ({ "gui wei", "herb_guiwei" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 3000);
        	set("weight", 50);
set("base_unit","块");
	}
	setup();
}
