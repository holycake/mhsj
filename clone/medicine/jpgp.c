// jpgp.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( MAG"健脾糕片" NOR, ({"jianpi gaopian", "gao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一块糕片，对调整气息有很好的用处。\n");
                set("base_unit", "包");
                set("value", 7000);
		set("unit","包");
                set("weight", 60);
                set("only_do_effect", 1);/*
                set("mixture", ([
                        "herb" : ([ "baishu"  : 1,
                                    "lianzi"  : 1,
                                    "gancao"  : 1,
                                    "chenpi"  : 1, 
                                 ]),
                        "neili"               : 90,
                        "gin"                : 70,
                        "time"                : 4,
                        "min_level"           : 60,
                        "medical"             : 80,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
          object me=this_player();

        if( !arg || arg != "jianpi gaopian" )
        {
                write("你要用什么药？\n");
                return 1;
        }
        if ( time() - me->query_temp("last_eat/gaopian") < 60 )
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }
        my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("你现在精神状态很好，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/gaopian", time());

        message_vision(YEL "$N" YEL "咬下一口" + name() +
                       YEL "嚼了一会，气色逐渐好转。\n" NOR, me);

        me->receive_curing("kee", 60);
        me->receive_heal("gin", 60);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
