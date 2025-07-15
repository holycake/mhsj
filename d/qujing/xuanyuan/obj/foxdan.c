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
        set_name(GRN"仙丹"NOR, ({"fox dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是在古墓的火炉中炼取的仙丹。\n");
                set("no_give",1);
                set("no_steal",1);
        	set("no_sell",1);
        }
        setup();
}

int do_eat(string arg)

{

        object me = this_player();

        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if(arg=="dan")
                {
                        me->set("eff_gin",me->query("max_gin"));
                        me->set("gin",me->query("max_gin"));
                        me->set("eff_kee",me->query("max_kee"));
                        me->set("kee",me->query("max_kee"));
message_vision(HIR"$N吃下丹，一股热流从丹田升起，顿时全身充满力量！\n"NOR,me);
                }
                destruct(this_object());
                me->start_busy(2);
                return 1;
}
