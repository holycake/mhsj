#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIR"养颜易容丹" NOR, ({ "dan", "yirong dan", "yirongdan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗色彩斑斓的丹药，不知道有什么用。\n");
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
        /*if (me->query("liwu/yirongdan") >= 5)
        {
        message_vision("$N的脸突然疼得要命。\n", me);
        tell_object(me, "你觉得没什么用。\n");
        } else
        if (random(5) == 0)
        {
        tell_object(me, "不过你觉得好像没什么作用。\n");
        } else
        {*/
        message("vision", "你似乎看见" + me->name() + "的练上好像脱了层皮。\n",
                                  environment(me), ({ me }));
        tell_object(me, HIY "你的脸活生生的掉了一层皮，可把你吓坏了，"
                                "好在一会儿就停了下来，似乎比以前更漂亮了。\n" NOR);
        me->add("per", 1);
        //}
        me->add("liwu/yirongdan", 1);
        destruct(this_object());
	 return 1;
}
