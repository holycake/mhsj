// Pill: bicanfeng.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"碧蚕粉"NOR, ({"bican feng", "feng"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一袋剧毒的毒药, 如果用来炼暗器有见血封喉之效. \n");
		set("unit", "袋");
		set("value", 20000);
	}
	setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	if(arg=="feng" || arg=="bican feng") 
	{
		message_vision("$N仰头把一小袋" + name() + "都咽了下去。\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
