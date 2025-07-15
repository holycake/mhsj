#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("你只能用先天乾坤功保护自己。\n");
        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 50 )
		return notify_fail("你的气血不足。\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

        message_vision(
                HIR"$N微一凝神，运起先天乾坤功，顿时身体一尺之外已经被罡气保护，水火不侵！\n" NOR, me);
        me->add_temp("apply/armor", skill/3);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的先天乾坤功运行一周天完毕，护体罡气渐渐消去了。\n");
	return;
}

