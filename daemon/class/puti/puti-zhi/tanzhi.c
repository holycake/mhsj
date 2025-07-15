// tanzhi.c
// Modify by Jingxue for XYCQ 2.13.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int success, ap, dp, time;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()           ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展『弹指惊魂』？\n");
        if(!me->is_fighting(target))
                return notify_fail("『弹指惊魂』只能在战斗中使用！\n");           if(target->is_busy())
                return notify_fail(target->query("name")+"已经不能动弹了。。。\n");  
        if((int)me->query_skill("unarmed",1) < 100)
                return notify_fail("你的『扑击格斗』等级需要100级！\n");
        if((int)me->query_skill("puti-zhi",1) < 100)
                return notify_fail("你的『菩 提 指』等级需要100级！\n");
        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不够200点！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精神！\n");
        weapon = me->query_temp("weapon");
        me->add("force", -200);
        me->receive_damage("sen", 20);
        msg = HIB"\n$N身影如旋风般舞动，指风破空之声嗤嗤不绝袭向$n各处要穴。\n"NOR;
        message_vision(msg, me, target);
        success = 1;
        ap = (random(me->query("combat_exp"))/8)*5 + me->query("combat_exp")/4;
      if(me->query("family/family_name") != "方寸山三星洞")
      ap = (random(me->query("combat_exp"))/8)*3 + me->query("combat_exp")/4;
        dp = ((int)target->query("combat_exp")/8)*3;
        if( ap < dp ) success = 0;
                if(success == 1 ){
                msg +=  HIB "$n"HIB"只觉胸口膻中穴一麻，登时动弹不得。\n\n" NOR;
                time = random((me->query_skill("unarmed") -100))+1;
                if(time>7) time=7;
                target->start_busy(time);
                }           
        else {
                msg +=  HIG "$n"HIG"就地一滚堪堪躲过了$N的指风！！\n" NOR;      
                      me->start_busy(1+random(1));  
                } 
        message_vision(msg, me, target);
        return 1;
}

