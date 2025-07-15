//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("taiji-jian",1);
        if ( extra < 200) return notify_fail("你的太极剑法还不够纯熟！\n");
        if( time()-(int)me->query_temp("taiji_end") < 3 )
                return notify_fail("此招不能使用太多！\n");
              if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［太极八卦阵］只能对战斗中的对手使用。\n");
        if ((int)me->query("force")<150)
                return notify_fail("你的内力不够。\n"); 
        me->add("force",-100);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$N"HIM"使出太极剑法中的绝招"HIW"［太极八卦阵］"HIM"，有如武当七侠同时出手，只见$N手中的"+weapon->name()+HIM"闪电般向$n攻出第一剑！\n\n" NOR,me,target);        
     if (random((int)me->query_skill("dodge", 1)/2)>random((int)target->query_skill("dodge")/5 ) )
        {
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIC"「燕子掠波」\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIG"「蜻蜓点水」\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"「八方神剑」\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"「御剑降魔」\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIB"「剑身出窍」\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIW"「太极八卦」\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
         
        message_vision(WHT"$N连出七剑，结果$n被攻了个手忙脚乱！\n" NOR,me,target);
        me->start_busy(1);
        }else { 
                message_vision(HIC"可是$n看破了$N的招式,趁机发动进攻！\n" NOR,me,target);
                me->start_busy(2);
        }        
         me->reset_action();
    me->set_temp("taiji_end",time());
   return 1;
}
