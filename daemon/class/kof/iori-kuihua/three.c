#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这[百贰拾七式.葵花]？\n");

        if(!me->is_fighting())
                return notify_fail("[百贰拾七式.葵花]只能在战斗中使用！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("iori-kuihua", 1) < 150)
                return notify_fail("你的[百贰拾七式.葵花]手级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");

        message_vision("\n$N使出-"HIY"[百贰拾七式.葵花]"NOR"-"BLINK HIR"绝技葵花三段"HIG".."NOR"\n", me);


        me->set_temp("kuihua_per", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"葵花一段"NOR"-------"BLINK HIR"百合折\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"葵花二段"NOR"-------"BLINK HIG"轰斧阴\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"葵花三段"NOR"-------"BLINK HIR"暗勾手\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("kuihua_per");

        me->receive_damage("kee", 50);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

