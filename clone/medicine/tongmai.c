// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(WHT "贯气通脉丹" NOR, ({"tongmai dan", "dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一粒药丸，看上去银光闪闪，好似"
                            "金属一般，实是效果极佳疗伤圣药。\n");
                set("unit", "粒");
                set("value", 4000);
                set("weight", 85);
set("base_unit","粒");/*
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
                                    "renshen"  : 1,
                                    "lurong"   : 1, ]),
                        "neili" : 150,
                        "jing"  : 40,
                        "time"  : 5,
                        "min_level" : 120,
                        "medical" : 150,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="tongmai dan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/tongmai") < 60)
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

        me->set_temp("last_eat/tongmai", time());

        message_vision(WHT "$N" WHT "把" + name() +
                       WHT "咕咚一声吞下了肚，立刻气色看起来好多了。\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
