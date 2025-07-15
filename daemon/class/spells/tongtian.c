//by mhsj@gslxz /2001/7/25
//
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

	if((string)me->query("zhiye")!="魔法师" )
		return notify_fail("只有魔法师才能够使用通天之术！\n");

        message_vision("$N喃喃地念了几句咒语。\n", me);

	me->add("mana", -25);
	me->receive_damage("sen", 20);

	if(me->is_fighting() ) {
		if(random((int)me->query("max_mana")) >(int)target->query("max_mana")/2) {
			message_vision(HIY"$N念了几句咒语接着就消失在空气之中。\n"NOR, me);
			me->move("/d/city/kezhan");
			tell_room(environment(me),
HIY"一阵强光过后"+me->query("name")+"出现在大家面前。\n\n"NOR, ({me, me}) );

		} else {
			message_vision(MAG"$N想使用通天之术，却被$n"MAG"拦住。\n"NOR, me, target);
			me->start_busy(2);
		}
	} else {
		message_vision(HIY"$N念了几句咒语接着就消失在空气之中。\n"NOR, me);
		me->move("/d/city/kezhan");
                tell_room(environment(me),
HIY"一阵强光过后"+me->query("name")+"出现在大家面前。\n\n"NOR, ({me, me}) );

	}

        return 5+random(5);
}

