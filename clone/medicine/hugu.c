// hugu.c   治疗伤寒，应该加大伤寒的危害。

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( GRN"虎骨酒" NOR, ({"hugu jiu", "jiu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一棕色的虎骨酒，历来对伤寒的治疗很见成效。\n");
                set("base_unit", "瓶");
                set("value", 5000);
                set("unit","瓶");
                set("weight", 50);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "hugu"      : 1,
                                    "renshen"   : 1,
                                    "duhuo"     : 1,
                                    "fangfeng"  : 1,
                                    "dangui"    : 1,
                                    "goujuzi"   : 1, 
                                 ]),
                        "neili"                 : 80,
                        "jing"                  : 35,
                        "time"                  : 1,
                        "min_level"             : 50,
                        "medical"               : 80,
                                ]));*/
             }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping my;
       
        if ( !arg || arg != "hugu jiu" )
        {
                write("你要用什么药？\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/hugu") < 20)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();

       
        if ( !( me->query_condition("ill_shanghan")) )
        {
                write("你现在没得伤寒，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/hugu", time());

        message_vision(HIW "$N" HIW "咕嘟咕嘟地灌下两口" + name() +
                       HIW "，看上去精神好多了。\n" NOR, me);

        me->apply_condition("ill_shanghan", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
