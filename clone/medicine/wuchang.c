// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIR "无常丹" NOR, ({"wuchang dan", "dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗晶莹火红的无常丹，是桃花岛精心练制的奇药。\n");
                set("unit", "颗");
                set("value", 8000);
                set("weight", 70);
set("base_unit","颗");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "tianqi"   : 1,
                                    "honghua"  : 1,
                                    "moyao"    : 1,
                                    "xiongdan" : 1,
                                    "heshouwu" : 2,
                                    "renshen"  : 2,
                                    "zzfen"    : 1,
                                    "xuelian"  : 1,
                                    "xuejie"   : 1,
                                    "renshen"  : 1 ]),
                        "force" : 400,
                        "jing"  : 60,
                        "time"  : 8,
                        "min_level" : 150,
                        "taohua-yaoli" : 250,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="wuchang dan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/wuchang") < 180)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        me->set_temp("last_eat/wuchang", time());

        message_vision(HIR "$N" HIR "吞下无常丹，脸色泛一阵红晕。\n" NOR, me);
        tell_object(me, HIY "你只觉得真气充沛，几乎就要澎湃而出。\n" NOR);

        log_file("nosave/using", sprintf("%s(%s) eat 无常丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        my = me->query_entire_dbase();
        my["force"] = my["max_force"] * 2;

        me->start_busy(3);
        destruct(this_object());
        return 1;
}
