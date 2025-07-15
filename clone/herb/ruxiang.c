// ruxiang.c

#include "herb.h"

void create()
{
	set_name(HIW "乳香" NOR, ({ "ru xiang", "herb_ruxiang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 500);
        	set("weight", 50);
set("base_unit","块");
	}
	setup();
}
