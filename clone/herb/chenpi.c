// chenpi.c

#include "herb.h"

void create()
{
	set_name(YEL "陈皮" NOR, ({ "chenpi", "herb_chenpi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "块");
		set("value", 10);
        	set("weight", 20);
set("base_unit","块");
	}
	setup();
}
