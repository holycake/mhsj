#include <ansi.h>
// arrow.c
 
#include <weapon.h>
 
inherit THROWING;

int is_arrow() { return 1; }
 
void create()
{
	set_name("凿子箭", ({ "zaozi jian", "arrow", "jian" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根细长的箭，箭翎修长，簇矢如月牙一般。\n");
		set("unit", "把");
		set("base_unit", "根");
		set("base_weight", 100);
		set("base_value", 13);
                set("wound_percent", 90);
	}

	set_amount(1);
	init_throwing(200);
	setup();

        set("no_wield", "这不是用来装备的。\n");
}
