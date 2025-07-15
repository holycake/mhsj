// dahuang.c

#include "herb.h"

void create()
{
	set_name(HIY "大黄" NOR, ({ "da huang", "herb_dahuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 7000);
        	set("weight", 100);
set("base_unit","块");
	}
	setup();
}
