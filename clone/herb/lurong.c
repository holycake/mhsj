// lurong.c

#include "herb.h"

void create()
{
	set_name(HIY "鹿茸" NOR, ({ "lurong", "herb_lurong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 10000);
        	set("weight", 70);
set("base_unit","块");
	}
	setup();
}
