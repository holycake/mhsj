// baochi.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIW "保赤一粒金" NOR, ({"yili jin", "jin"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种小药丸，具有恢复体力的效果。\n");
                set("base_unit", "包");
                set("value", 10000);
                set("unit", "包");
                set("weight", 40);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "niuhuang" : 1,
                                    "zhusha"   : 1,
                                    "beimu"    : 1,
                                    "hupo"     : 1,
                                 ]),
                        "neili"                : 80,
                        "jing"                 : 35,
                        "time"                 : 1,
                        "min_level"            : 50,
                        "medical"              : 80,
                                ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/ylj") < 100)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();

        if (my["kee"] >= 3*my["max_kee"]/4)
        {
                write("你现在体力充沛，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/ylj", time());

        message_vision(HIW "$N" HIC"把" + name() +"硬吞了下去"
                       HIW "，顿时浑身充满了力量。\n" NOR, me);
       
        me->set("kee","max_kee");
        me->start_busy(1);
        destruct(this_object());
        return 1;
}
