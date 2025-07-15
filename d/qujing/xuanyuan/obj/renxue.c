// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
       set_name(HIR"鲜血"NOR ,({"xian xue","xue"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("long", "一碗鲜红的鲜血.\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 60);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "江米酒",
                "drunk_apply": 10,
        ]));
}
void init()
{
    add_action("do_drink", "drink");
}
int do_drink(string arg)
{
    object me = this_player();

    if (!id(arg)) return 0;
    if (!living(me)) return 1;

    if (me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");

    if( query("food_remaining") <= 0 )
        return notify_fail(name() + "已经没有什么可以喝的了。\n");

    if( me->query("water") >= me->max_water_capacity() )
        return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

    // 模拟 eat 的效果，加 food 和 water
    add("food_remaining", -1);
    me->add("food", query("food_supply"));
    me->add("water", query("food_supply")); // 加水值

    message_vision("$N端起" + name() + "喝了一口鲜血，鲜红的液体顺着嘴角滴落……\n", me);

    if( query("food_remaining") == 0 )
        write("你已经将" + name() + "喝得一滴也不剩了。\n");

    if( me->is_fighting() ) me->start_busy(2);
    return 1;
}
