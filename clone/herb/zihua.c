// zihua.c

#include "herb.h"

void create()
{
	set_name(MAG "紫花" NOR, ({ "zihua", "herb_zihua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 50);
        	set("weight", 20);
set("base_unit","朵");
	}
	setup();
}
