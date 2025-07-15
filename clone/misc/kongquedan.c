// Pill: kongquedan.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(BLU"孔雀胆"NOR, ({"kongque dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一瓶剧毒的毒药, 如果用来炼暗器有见血封喉之效. \n");
		set("unit", "粒");
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
	if(arg=="hong" || arg=="heding hong") 
	{
		message_vision("$N仰头张口吞下一粒" + name() + "。\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
