// xiandan2.c 未名仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "仙丹" NOR, ({ "dan", "xian dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗园园的火红仙丹，据说吃了可以增强灵性。\n");
                set("value", 10000);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        
                tell_object(me, HIM "霎时间你觉得腿骨欲裂，一时疼痛难忍，晕了过去。\n" NOR);
                me->add("spi", 1);

        destruct(this_object());
	return 1;
}
