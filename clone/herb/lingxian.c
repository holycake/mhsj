// lingxian.c

#include "herb.h"

void create()
{
	set_name(MAG "灵仙" NOR, ({ "ling xian", "herb_lingxian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 5000);
        	set("base_weight", 40);
	}
	setup();
}
