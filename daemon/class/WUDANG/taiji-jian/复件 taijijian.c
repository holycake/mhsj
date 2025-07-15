#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「太极剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「太极剑」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

	i=(int)me->query_skill("taiji-jian",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("你的太极剑法级别还不够，使用这一招会有困难！\n");

              if( i > 1/100)
              {
message_vision(HIW"\n$N略一凝神，手中的"+me->query_temp("weapon")->name()+"划出一道剑光"NOR,me,target);
message_vision(HIR"\n一刹那间剑虹破空而来，劈面罩向$n"NOR,me,target);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        me->set_temp("QJB_perform",7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->start_busy(2);
        me->add("force", -300);    
        target->start_busy(1);
}
              else {
           message_vision(HIY"\n$n左闪右躲，好不容易避开了一轮剑虹"NOR,me,target);
me->add("force", -100);
me->start_busy(1);
}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
              return 1;
}
