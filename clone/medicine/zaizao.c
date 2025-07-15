// zaizao

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( "[1;32m人[33m参[35m再[36m造[37m丸[m", ({"zaizao wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗色彩缤纷的药丸，想必药效一定很奇特。\n");
                set("unit", "颗");
                set("value", 1200);
                set("weight", 80);
set("base_unit","颗");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "renshen"    : 1,
                                    "xuejie"     : 1,
                                    "heshouwu"   : 1,
                                    "shexiang"   : 1,
                                    "xiefen"     : 1,
                                    "fangfeng"   : 1,
                                    "moyao"      : 1,
                                    "dahuang"    : 1,
                                    "juhua"      : 1,
                                    "sanjia"     : 1,
                                    "dangui"     : 1,
                                    "gancao"     : 1 ]),
                        "force" : 300,
                        "gin"  : 50,
                        "time"  : 5,
                        "min_level" : 140,
                        "medical" : 200,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="zaizao wan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/zaizao") < 120)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        me->set_temp("last_eat/zaizao", time());

        message_vision(HIG "$N" HIG "吃下一粒" + name() +
                       HIG "，只觉得自己好象变了一个人。\n", me);

        log_file("nosave/using", sprintf("%s(%s) eat 人参再造丸 at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

        my = me->query_entire_dbase();
        my["eff_sen"] = my["max_sen"];
        my["sen"] = my["max_sen"];
        my["eff_kee"] = my["max_kee"];
        my["kee"] = my["max_kee"];
        if (my["force"] < my["max_force"])
                my["force"] = my["max_force"];
        if (my["mana"] < my["max_mana"])
                my["mana"] = my["max_mana"];
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
