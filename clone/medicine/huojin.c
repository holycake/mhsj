// huojin.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(MAG "活筋舒血丸" NOR, ({"huojin wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一粒药丸，呈现出淡淡的粉色，疗伤效果颇为不错。\n");
                set("base_unit", "粒");
                set("value", 2000);
                set("unit","粒");
                set("weight", 60);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "honghua"  : 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1,
                                    "yjhua"    : 1,
                                    "heshouwu" : 1, 
                                  ]),
                        "neili"                : 80,
                        "jing"                 : 30,
                        "time"                 : 3,
                        "min_level"            : 80,
                        "medical"              : 90,
                                ]));*/
            }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        if( !arg || arg != "huojin wan" )
        {
                write("你要用什么药？\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/huojin") < 80)
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

        me->set_temp("last_eat/huojin", time());

        message_vision(MAG "$N" MAG "小心的吞下了" + name() +
                       MAG "，运了两口气，脸色看起来好多了。\n" NOR, me);

        me->receive_curing("kee", 350);
        me->receive_heal("kee", 350);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
