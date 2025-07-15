// honghua.c

#include "herb.h"

void create()
{
	set_name(HIR "红花" NOR, ({ "honghua", "herb_honghua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 800);
        	set("weight", 20);
set("base_unit","朵");
	}
	setup();
}
