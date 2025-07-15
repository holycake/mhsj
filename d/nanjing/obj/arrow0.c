#include <ansi.h>
// arrow.c
 
#include <weapon.h>
 
inherit THROWING;

int is_arrow() { return 1; }
 
void create()
{
	set_name("细竹枝", ({ "xizhu jian", "arrow", "jian" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根细长的竹枝，一端被削尖，另一端绑了两三根羽毛，勉强可以当箭来用。\n");
		set("unit", "把");
		set("base_unit", "根");
		set("base_weight", 100);
		set("base_value", 3);
                set("wound_percent", 80);
	}

	set_amount(1);
	init_throwing(200);
	setup();

        set("no_wield", "这不是用来装备的。\n");
}
