#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「烈火焚身」?\n");
        weapon = me->query_temp("weapon");
        if(!me->is_fighting())
                return notify_fail("「烈火焚身」只能在战斗中使用!\n");

                                if(me->query("family/family_name")!="火云洞")
return notify_fail("“祭枪”只有火云洞门人才可以用！\n");
   if((int)me->query("max_force") < 1200)
     return notify_fail("你的内力太弱！\n");
   if((int)me->query("force") < 400 )
     return notify_fail("你的内力不足！\n");
   if((int)me->query_skill("huoyun-qiang", 1) < 100)
     return notify_fail("你的火云枪等级还不够!!\n");
    msg = HIR
"\n$N手中的"+weapon->name()+""+HIR"抖出满天红霞,裹住$n全身,正是一招「烈火焚身」!!\n"NOR;
message_vision(msg, me, target);
   me->delete("env/brief_message");
   target->delete("env/brief_message");
        me->set_temp("HYQ_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("HYQ_perform");
        me->add("force", -150);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                }
        }
        me->start_busy(1+random(1));
        return 1;
}
