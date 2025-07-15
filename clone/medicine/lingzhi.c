// lingzhi.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( "[1;37m灵[32m芝[33m重[34m生[36m露[m", ({"chongsheng lu", "lu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种极珍贵的药品，有起死回生之功效。\n");
                set("base_unit", "滴");
                set("base_value", 100000);
                set("base_weight", 80);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "lingzhi"   : 1,
                                    "renshen"   : 1,
                                    "heshouwu"  : 1,
                                    "lingxian"  : 1,
                                    "shexiang"  : 1,
                                    "bohe"      : 1,
                                    "bingpian"  : 1,
                                    "tiandong"  : 1,
                                    "chenpi"    : 1 
                                  ]),
                        "neili"                 : 300,
                        "jing"                  : 50,
                        "time"                  : 5,
                        "min_level"             : 140,
                        "medical"               : 200,
                                ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/lingzhi") < 120)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        me->set_temp("last_eat/lingzhi", time());

        message_vision(HIG "$N" HIG "喝下一滴灵芝重生露后，只觉得瞳子穴、大敦穴"
                            "气冲穴、冲阳穴四处气流融汇，真是无比舒畅。\n", me);

        log_file("nosave/using", sprintf("%s(%s) eat 灵芝重生露 at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

        my = me->query_entire_dbase();
        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        if (my["jingli"] < my["max_jingli"])
                my["jingli"] = my["max_jingli"];
        if (my["neili"] < my["max_neili"])
                my["neili"] = my["max_neili"];

        me->start_busy(3);
        destruct(this_object());
        return 1;
}
