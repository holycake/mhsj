// jyzgao.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIY "金樱子膏" NOR, ({"jinyingzi gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种金黄色的膏药，看起来很诱人。\n");
                set("base_unit", "瓶");
                set("base_value", 11000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "jinyingzi"  : 1,
                                    "water"      : 1,
                                 ]),
                        "neili"                  : 70,
                        "jing"                   : 25,
                        "time"                   : 1,
                        "min_level"              : 50,
                        "medical"                : 80,
                               ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/jyz") < 80)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("你现在并没有受伤，不必服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/jyz", time());

        message_vision(CYN "$N" CYN "在伤处涂抹了一些" + name() +
                       CYN "，顿时觉得一股凉气直通心脾。\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
