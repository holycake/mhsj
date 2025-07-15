// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"万年雪莲"NOR, ({"xu lian", "lian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵武林人士梦寐以求的万年雪莲，据说吃一棵可得100内力上限。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("max_neili", 100);
	this_player()->add("eff_neili",100);
	message_vision("$N吃下一棵万年雪莲，只觉得自己的内力变利害了一些 !\n", this_player());
	destruct(this_object());
	return 1;
}

