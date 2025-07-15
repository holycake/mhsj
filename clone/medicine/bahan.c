
#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIR "武力拔寒散" NOR, ({"wulibahan san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一片红色的药片，有祛风散寒、活血止痛的功效。\n");
                set("base_unit", "片");
                set("value", 5000);
                set("weight", 50);
                set("unit","片");
        }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if(! arg || arg!="wulibahan san")
                {
                write("你使用什么药？\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/bahan") < 100)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }



        if ( !(me->query_condition("ill_shanghan")) )
         {
                write("你没有得伤寒，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/bahan", time());

        message_vision(HIW "$N" HIW "服下一片" + name() +HIW "之后，看上去精神好多了。\n" NOR, me);

        me->apply_condition("ill_shanghan", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
