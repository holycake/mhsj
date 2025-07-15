// yjhua.c

#include "herb.h"

void create()
{
	set_name(YEL "洋金花" NOR, ({ "yang jinhua", "herb_yjhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "朵");
		set("value", 400);
        	set("weight", 20);
set("base_unit","朵");
	}
	setup();
}
