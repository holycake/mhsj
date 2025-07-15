//jyhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(  HIY"金[1;37m银[32m花[36m露[m" NOR, ({"jinyinhua lu", "lu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一瓶特制的金银花露，害怕热的人一般都会有随身携带这种药品。。\n");
                set("base_unit", "瓶");
                set("unit","瓶");
                set("value", 5000);
                set("weight", 50);
                set("only_do_effect", 1);/*
                set("mixture", ([
                        "herb"      : ([ "jyhua"  : 1, ]),
                        "neili"     : 80,
                        "jing"      : 35,
                        "time"      : 1,
                        "min_level" : 50,
                        "medical"   : 80,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
         object me=this_player();

        if( !arg || arg != "jinyinhua lu" )
        {
                write("你要用什么药？\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/jyhua") < 20)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();

        
        if ( !(me->query_condition("ill_zhongshu")) )
        {
                write("你现在没有中暑，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/jyhua", time());

        message_vision(HIW "$N" HIW "抹了点" + name() +"在太阳穴上"
                       HIW "，顿时感动清爽多了。\n" NOR, me);

        me->apply_condition("ill_zhongshu", 0);
        
        me->receive_curing("kee", 30);
        me->receive_heal("kee", 30);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
