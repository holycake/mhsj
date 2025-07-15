// hafen

#include "herb.h"

void create()
{
	set_name(RED "蛤粉" NOR, ({ "ha fen", "herb_hafen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "包");
		set("value", 5000);
        	set("weight", 50);
set("base_unit","包");
	}
	setup();
}
