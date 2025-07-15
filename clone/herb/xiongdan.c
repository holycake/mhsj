// xiongdan.c

#include "herb.h"

void create()
{
	set_name(HIR "熊胆" NOR, ({ "xiongdan", "herb_xiongdan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "个");
		set("value", 5000);
        	set("weight", 70);
set("base_unit","个");
	}
	setup();
}
