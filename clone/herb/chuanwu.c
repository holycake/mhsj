// chuanwu.c

#include "herb.h"

void create()
{
	set_name(WHT "川乌" NOR, ({ "chuanwu", "herb_chuanwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "根");
		set("value", 200);
        	set("weight", 50);
set("base_unit","块");
	}
	setup();
}
