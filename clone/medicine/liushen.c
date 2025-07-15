//liushen.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIB"六神丸" NOR, ({"liushen wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种很常见的药丸，用来治疗发烧。\n");
                set("base_unit", "粒");
                set("unit", "粒");
                set("value", 5000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "niuhuang"  : 1,
                                    "xiongdan"  : 1,
                                    "chansu"    : 1,
                                    "bingpian"  : 1,
                                  ]),
                        "neili"                 : 40,
                        "jing"                  : 35,
                        "time"                  : 1,
                        "min_level"             : 40,
                        "medical"               : 60,
                               ]));
        }
        setup();
}


int do_eat(string arg)
{
        int duration;
        object me=this_player();
        mapping my;

        if ( !arg || arg != "liushen wan" )
        {
                write("你要用什么药？\n");
                return 1;
        }

        duration = me->query_condition("ill_zhongshu");
 
        my = me->query_entire_dbase();

        if ( duration = 0 )
        {
                write("你现在精神状态很好，无需服用" + name() + "。\n");
                return 1;
        }


        message_vision(HIW "$N" HIW "吞下一粒" + name() +
                       HIW "，顿时觉得清醒了不少。\n" NOR, me);

        me->apply_condition("ill_fashao", 0);

        me->receive_curing("kee", 50);
        me->receive_heal("gin", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
