// shancha.c

#include "herb.h"

void create()
{
	set_name(WHT "山茶花" NOR, ({ "shancha", "herb_shancha" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 200);
        	set("weight", 20);
set("base_unit","朵");
	}
	setup();
}
