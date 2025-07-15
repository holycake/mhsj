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
                return notify_fail("你要对谁施展这一招「太极拳」？\n");

        if(!me->is_fighting())
                return notify_fail("「太极拳」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

              i=(int)me->query_skill("taiji-quan",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("你的太极拳法别还不够，使用这一招会有困难！\n");

	message_vision(HIC"$N大吼一声：麒麟何在？手中"+me->query_temp("weapon")->name()+
                                      HIC"瞬间颤抖，使出了「麒麟九式」的精髓！\n"NOR,me,target);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("kee", 200);
        me->add("force", -1000);
             me->start_busy(5);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

