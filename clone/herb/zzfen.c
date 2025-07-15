// zzfen.c

#include "herb.h"

void create()
{
	set_name(HIW "珍珠粉" NOR, ({ "zhenzhu fen", "herb_zzfen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "包");
		set("value", 9000);
        	set("weight", 30);
set("base_unit","包");
	}
	setup();
}
