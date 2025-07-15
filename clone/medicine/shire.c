// shire.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "湿热正气丸" NOR, ({"shire wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "别看这只是小小的一粒药丸，对增加真气是很有效的。\n");
                set("unit", "粒");
                set("value", 10000);
                set("weight", 50);
set("base_unit","粒");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "honghua"  : 1,
                                    "dingxiang": 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1, 
                                  ]),
                        "neili"                : 70,
                        "jing"                 : 25,
                        "time"                 : 1,
                        "min_level"            : 50,
                        "medical"              : 80,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="shire wan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/shire") < 20)
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

        me->set_temp("last_eat/shire", time());

        message_vision(CYN "$N" CYN "张开嘴，猛地吞下了" + name() +
                       CYN "，轻轻的哼了一声。\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
