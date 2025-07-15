// xiudaodan.c 修道丹
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
 set_name(HIG"潜能丹"NOR, ({"dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
     set("unit", "颗");
set("long","这是一棵武林人士梦寐以求的修道丹，据说吃一棵可得1年得道行，1000潜能。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

// this_player()->add("daoxing", 1000);
this_player()->add("potential",200000);
 message_vision("$N吃下一颗修道丹，只觉得自己的道行又变利害了一些 !\n", this_player());
            destruct(this_object());
	return 1;
}

