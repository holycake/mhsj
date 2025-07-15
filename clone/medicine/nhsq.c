//　牛黄上清丸:本品由荆芥穗、防风、薄荷、菊花、蔓荆子、连翘、桔梗、黄
//芩、黄连、黄柏、栀子、大黄、冰片、生石膏、川芩、白芷、旋复花、甘草制
//成。

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "牛黄上清丸" NOR, ({"shangqing wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种常见的药丸，用来清气血。\n");
                set("unit", "片");
                set("value", 10000);
		set("base_unit","片");
                set("weight", 50);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "niuhuang"  : 1,
                                    "bohe"      : 1,
                                    "juhua"     : 1,
                                    "gancao"    : 1,
                                    "liankeeao"  : 1,
                                    "fangfeng"  : 1,
                                    "bingpian"  : 1,
                                    "huanglian" : 1,
                                  ]),
                        "neili"                 : 90,
                        "jing"                  : 65,
                        "time"                  : 1,
                        "min_level"             : 40,
                        "medical"               : 70,
                               ]));*/
        }
        setup();
}

int do_eat(string arg) 
{
	object me=this_player();
	if( !arg || arg !="shangqing wan" )
	{
		write("你要使用什么药？\n");
		return 1;
	}
        if (time() - me->query_temp("last_eat/nhsq") < 20)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        if (time() - me->query_temp("last_eat/nhsq") < 20)
        {
                write("你现在精神状态很好，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/nhsq", time());

        message_vision(HIW "$N" HIW "服下一片" + name() +
                       HIW "之后，看上去精神好多了。\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
