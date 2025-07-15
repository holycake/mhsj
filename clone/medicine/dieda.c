// dieda.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "跌打伤愈膏" NOR, ({"dieda gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一块胶状的东西，疗伤效果比金创药要好一些。\n");
                set("unit","包");
                set("base_unit", "包");
                set("value", 10000);
                set("unit", "包");
                set("base_weight", 50);
                set("mixture", ([
                                    "chuanwu"  : 1,
                                    "honghua"  : 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1, ]));
        }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping my;
        my = me->query_entire_dbase();

        if(! arg || arg != "gao")
                {
                write("你要吃什么药？\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/dieda") < 10)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        if (my["eff_kee"] == my["max_kee"])
        {
                write("你现在并没有受伤，不必服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/dieda", time());

        message_vision(CYN "$N" CYN "张开嘴，猛地吞下了" + name() +
                       CYN "，轻轻的哼了一声。\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
