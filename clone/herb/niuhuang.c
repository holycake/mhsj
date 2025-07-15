// niuhuang.c

#include "herb.h"

void create()
{
	set_name(HIY "牛黄" NOR, ({ "niu huang", "herb_niuhuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "颗");
		set("value", 1000);
        	set("weight", 60);
set("base_unit","颗");
	}
	setup();
}
