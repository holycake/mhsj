// fangfeng.c

#include "herb.h"

void create()
{
	set_name(HIB "防风" NOR, ({ "fang feng", "herb_fangfeng" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "片");
		set("value", 500);
        	set("weight", 40);
set("base_unit","片");
	}
	setup();
}
