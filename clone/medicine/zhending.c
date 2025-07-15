// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(YEL "固元镇定散" NOR, ({"zhending san", "san"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一包淡黄色的粉末，具有神奇的镇定效果。\n");
                set("unit", "包");
                set("value", 50000);
                set("weight", 60);
set("base_unit","包");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "xuejie"   : 1,
                                    "yjhua"    : 1,
                                    "xiongdan" : 1,
                                    "shancha"  : 1,
                                    "gsliu"    : 1,
                                    "zzfen"    : 1,
                                    "xuelian"  : 1,
                                    "lurong"   : 1, ]),
                        "neili" : 150,
                        "gin"  : 60,
                        "time"  : 5,
                        "min_level" : 120,
                        "medical" : 150,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        if(! arg || arg!="zhending san")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/zhending") < 10)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_gin"] == my["max_gin"])
        {
                write("你现在精神状态很好，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/zhending", time());

        message_vision(YEL "$N" YEL "一张嘴，吞下了" + name() +
                       YEL "，看上去精神好多了。\n" NOR, me);

        me->receive_curing("gin", 300);
        me->receive_heal("gin", 300);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
