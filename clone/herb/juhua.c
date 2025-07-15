// juhua.c

#include "herb.h"

void create()
{
	set_name(HIY "菊花" NOR, ({ "juhua", "herb_juhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 60);
        	set("weight", 20);
set("base_unit","朵");
	}
	setup();
}
