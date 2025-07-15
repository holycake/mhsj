#include <ansi.h>
// arrow.c
 
#include <weapon.h>
 
inherit THROWING;

int is_bullet() { return 1; }
 
void create()
{
	set_name("铅弹", ({ "bullet", "qian dan", "zidan" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是专门用于火器射击的弹药。每一颗的大小都相差无几。\n");
		set("unit", "些");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 3);
                set("wound_percent", 80);
	}

	set_amount(1);
	init_throwing(20);
	setup();

        set("no_wield", "这不是用来装备的。\n");
}
