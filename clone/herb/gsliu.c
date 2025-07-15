// gsliu.c

#include "herb.h"

void create()
{
	set_name(CYN "干石榴" NOR, ({ "gan shiliu", "herb_gsliu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "片");
		set("value", 200);
        	set("weight", 75);
set("base_unit","片");
	}
	setup();
}
