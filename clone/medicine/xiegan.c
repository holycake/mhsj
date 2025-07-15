// xiegan.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "龙胆泻肝丸" NOR, ({"xiegan wan", "wan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗棕色的药丸，看起来很苦。\n");
                set("unit", "包");
                set("value", 20000);
                set("weight", 60);
set("base_unit","包");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "lanhua"   : 1,
                                    "xuejie"   : 1,
                                    "yjhua"    : 1,
                                    "sumu"     : 1,
                                    "shancha"  : 1,
                                    "tiankee"   : 1,
                                    "lingxian" : 1,
                                 ]),
                        "neili"                : 100,
                        "gin"                 : 50,
                        "time"                 : 3,
                        "min_level"            : 70,
                        "medical"              : 100,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="xiegan wan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/xiegan") < 20)
        {
                write("你是不是不要命了？刚才不是才泄过吗？\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["food"] <= my["max_food_capacity()"]/4 && my["water"] <= my["max_water_capacity()"]/4)
        {
                write("你现在饥肠碌碌，哪里还能用什么" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/xiegan", time());
        message_vision(HIG "$N" HIG "一口就把" + name() +"吞了下去，说来真见效"
                       HIG "$N马上上吐下泄起来。\n" NOR, me);
        
        my["eff_kee"] = my["max_kee"];
        my["eff_gin"] = my["max_gin"];

        me->set("food", 0);
        me->set("water",0);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}
