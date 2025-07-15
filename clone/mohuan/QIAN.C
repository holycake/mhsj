// lingzhi.c 冰糖葫芦
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
	set_name(HIM"冰糖葫芦"NOR, ({"hulu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("long", "这是一棵武林人士梦寐以求的冰糖葫芦，据说吃一棵可得500经验，200潜能。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

this_player()->add("potential",10000);
	message_vision("$N吃下一串冰糖葫芦，只觉得自己又变利害了一些 !\n", this_player());
            destruct(this_object());
	return 1;
}

