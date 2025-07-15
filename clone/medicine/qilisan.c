// qilisan.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( GRN "七厘散" NOR, ({"qili san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个小药片，用来治疗跌扑损伤，瘀滞肿痛。\n");
                set("base_unit", "包");
                set("value", 12000);
		set("unit","包");
                set("weight", 50);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "shexiang"  : 1,
                                    "bingpian"  : 1,
                                    "moyao"     : 1,
                                    "xuejie"    : 1,
                                    "zhusha"    : 1,
                                 ]),
                        "neili"                 : 90,
                        "jing"                  : 50,
                        "time"                  : 1,
                        "min_level"             : 50,
                        "medical"               : 90,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="qili san")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/qili") < 20)
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

        me->set_temp("last_eat/qili", time());

        message_vision(CYN "$N" CYN "把" + name() +"放到嘴里"
                       CYN "，顿时脸就变的红润起来了。\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
