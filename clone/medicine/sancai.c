// sancai.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( MAG"三才封髓丹" NOR, ({"sancai dan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种十分珍贵的药丸，对增加功力大有益处。\n");
                set("unit", "粒");
                set("value", 6000);
                set("weight", 50);
set("base_unit","粒");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "tiandong"  : 1,
                                    "renshen"   : 1,
                                    "gancao"    : 1,
                                    "guiwei"    : 1,
                                    "dangui"    : 1,
                                    "huangbo"   : 1,
                                 ]),
                        "force"                 : 150,
                        "jing"                  : 205,
                        "time"                  : 4,
                        "min_level"             : 150,
                        "medical"               : 180,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="sancai dan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query("last_eat/sancai") < 900)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["combat_exp"] <= 100000 )
        {
                write("你现在经验太少，吃了" + name() + "也是没用。\n");
                return 1;
        }

        me->set("last_eat/sancai", time());

        message_vision(CYN "$N" CYN "吃下" + name() +
                       CYN "，顿时青筋暴长。\n" NOR, me);

        me->add("max_force", 3);
        me->add("max_mana",3);
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
