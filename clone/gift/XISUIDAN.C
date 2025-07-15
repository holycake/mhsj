// xisuidan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "洗髓丹" NOR, ({ "dan", "xisui dan", "xisuidan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗园园的仙丹，据说吃了可以增强根骨。\n");
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
        
                tell_object(me, HIY "你浑身的骨骼登时哗啦啦的响个不停，可把你吓坏了，"
                                "好在一会儿就听了下来，似乎筋骨更灵活了。\n" NOR);
                me->add("con", 1);
       
        destruct(this_object());
	return 1;
}
