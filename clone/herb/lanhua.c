// lanhua.c

#include "herb.h"

void create()
{
	set_name(HIB "兰花" NOR, ({ "lanhua", "herb_lanhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 500);
        	set("weight", 20);
set("base_unit","朵");
	}
	setup();
}
