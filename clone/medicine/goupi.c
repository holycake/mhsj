//　　狗皮膏：本品由生川乌、川芎、羌活、续断、穿山甲、血竭、乳香、没药等
//四十几种中药制成。具有祛风散寒、舒经活血止痛的功能。主治风湿冷痛，肌体
//麻木，瘀血疼痛等症。适用于慢性风湿性及类风湿性关节炎、跌打损伤等。

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( YEL "狗皮膏药" NOR, ({"goupi gaoyao", "gaoyao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一黑乎乎的东西，在药店里面十分常见。\n");
                set("base_unit", "块");
                set("value", 12000);
		set("unit","块");
                set("weight", 60);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "duanxu"           : 1,
                                    "shanjia"          : 1,
                                    "fangfeng"         : 1,
                                    "moyao"            : 1,
                                    "ruxiang"          : 1, 
                                 ]),
                        "neili"                        : 80,
                        "jing"                         : 50,
                        "time"                         : 3,
                        "min_level"                    : 20,
                        "medical"                      : 50,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
	object me=this_player();
	if( !arg || arg != "goupi gaoyao" )
	{
		write("你要吃什么药？\n");
		return 1;
	}
        if (time() - me->query_temp("last_eat/goupi") < 20)
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

        me->set_temp("last_eat/goupi", time());

        message_vision(HIG "$N" HIG "把" + name() +"放在手上，"
                       HIG "顺着伤口贴了上去\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
