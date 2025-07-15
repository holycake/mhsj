// gun.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_shoot","shoot");
}

void create()
{
	set_name(HIC"空气枪"NOR, ({ "air gun","gun" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
    set("no_get", 1);
		set("material", "steel");
		set("long", "这是一把小叮当用的空气枪，专门用来打昏坏蛋。\n");
		set("wield_msg", HIM"$N把空气枪套在手上。\n"NOR);
		set("unequip_msg", HIM"$N把空气枪从手上取了下来。\n"NOR);
	}
	init_blade(100);
	setup();
}

int do_shoot(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("你想打昏谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj == me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

obj->unconcious();
	return 1;
}

