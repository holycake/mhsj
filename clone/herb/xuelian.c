// xuelian.c

#include "herb.h"

void create()
{
	set_name(HIW "雪莲" NOR, ({ "xuelian", "herb_xuelian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 30000);
        	set("weight", 40);
set("base_unit","朵");
	}
	setup();
}
