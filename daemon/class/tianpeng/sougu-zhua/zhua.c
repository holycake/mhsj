// mhsj@gslxz /2001/7/25
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        string classname;
        classname = me->query("family/family_name");
        if(classname!="天蓬府")
                return notify_fail(WHT"只有天蓬府的弟子才能够使用"RED"[搜骨夺命爪]"NOR+WHT"。\n"NOR);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(RED"「搜骨夺命爪」"WHT"只能对战斗中的对手使用。\n"NOR);

        if (me->query_temp("weapon")||me->query_temp("second_weapon"))
                return notify_fail("空手才能使用[搜骨夺命爪].\n");
                
        if( (int)me->query_skill("sougu-zhua", 1) < 100 )
                return notify_fail("你的搜骨爪不够娴熟，不会使用「搜骨夺命爪」。\n");
                                        
        if( (int)me->query("force", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用「搜骨夺命爪」。\n");
                        
        msg = CYN"只见$N将所有内力运到双手上，向着$n"NOR+CYN"发出致命一击,\n$n"NOR+CYN"大惊失色，被$N发出的"NOR+RED"[搜骨夺命爪]"CYN"吓坏了。\n"NOR;

        if(random(me->query_skill("force")) >target->query_skill("force")/5)
        {
                target->start_busy((int)me->query_skill("six_finger")/40 +1);
                
                damage = 100+(int)me->query_skill("tianpeng-force", 1);
                damage = damage +  (int)me->query_skill("xbuddhism", 1);
                damage = damage +  (int)me->query_skill("sougu-zhua", 1);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/1);
                me->add("force", -500);
                msg += RED"一瞬间，几个血洞自$n"RED"身上出现，鲜血从中喷涌而出！！\n"NOR;
                me->start_busy(1);

        } else 
        {
                target->start_busy(1+random(1));
                msg += CYN"$n"NOR+CYN"顿时手忙脚乱，狼狈不堪。\n"NOR;
                me->add("force", -200);
                me->start_busy(1);
        }
        message_vision(msg, me, target);

        return 1;
}

