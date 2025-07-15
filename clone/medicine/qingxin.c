// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "清心解毒丸" NOR, ({"qingxin wan", "wan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一包淡绿色的粉末，解大雪山的毒有很好的效果。\n");
                set("unit", "包");
                set("value", 2000);
                set("weight", 60);
set("base_unit","包");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "xuejie"   : 1,
                                    "yjhua"    : 1,
                                    "xiongdan" : 1,
                                    "shancha"  : 1,
                                    "gsliu"    : 1,
                                    "zzfen"    : 1, ]),
                        "neili" : 100,
                        "gin"  : 50,
                        "time"  : 3,
                        "min_level" : 80,
                        "medical" : 100,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="qingxin wan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/qingxin") < 60)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();

        me->set_temp("last_eat/qingxin", time());

        message_vision(HIG "$N" HIG "一张嘴，吞下了" + name() +
                       HIG "，看上去毒清了不少。\n" NOR, me);

      me->apply_condition("yz_poison", 0 );
      me->apply_condition("bp_poison", 0 );
 
       me->receive_curing("gin", 150);
        me->receive_heal("gin", 150);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
