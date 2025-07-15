// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


skill = me->query_skill("shushan-force",1);

	if( skill > 250 ) {
		skill=250;
	}

        if( (int)me->query("force") < skill*2 )     
		return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
 HIR "$N定睛闭目，充分燃烧起自己的小宇宙，以提高自己的攻击力。。。\n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
	me->add_temp("apply/strength", - amount);
        me->delete_temp("powerup");
tell_object(me, "你的小宇宙已经燃烧尽了，还是赶快收功吧。\n");
}

