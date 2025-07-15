// heshouwu.c

#include "herb.h"

void create()
{
	set_name(HIW "何首乌" NOR, ({ "shouwu", "herb_heshouwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "根");
		set("value", 10000);
        	set("weight", 85);
set("base_unit","根");
	}
	setup();
}
