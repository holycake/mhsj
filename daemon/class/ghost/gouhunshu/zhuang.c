// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

// arrow.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;
                if(me->query("family/family_name") != "阎罗地府")
        return notify_fail("非鬼族不能使。\n");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展元神撞？\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你无法分出元神冲撞敌人！\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIC
"$N口中念了几句咒文，突然向后退了一步，留出自己的元神站在原来的位置上。\n
只见$N的元神一面部颤动，狰狞万分，露出一幅让人恐怖的青色鬼面\n
随着“嗷”的一声冲天巨吼，$N的元神直直冲向$n！\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
                random((int)me->query("eff_sen") / 10);
                damage -= (int)target->query("max_mana") / 10 +
                random((int)target->query("eff_sen") / 10);
                damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
                if( damage > 0 ) {
                        damage +=damage+random((damage*(int)me->query_skill("spells"))/200);
                        msg += HIR "结果$n被$N的元神那张狰狞的面孔吓得不敢动弹，
被撞得飞了出去。\n$N的元神又回到$N的身体里。\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/2, me);
                        target->receive_damage("kee", damage*2/3, me);
                        target->receive_wound("kee", damage/5, me);
                        me->improve_skill("gouhunshu", 1, 1);
                }
       else {
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note, damage<0.
                        msg += HIR "$n看着$N的元神迎面冲了过来，于是大吼了一声。
\n谁知这一巨吼竟然将$N的元神冲散，消失得无影无踪了。\n$N顿时口吐鲜血，少了此元神
的$N有些精神恍惚了。\n" NOR;
     damage -= (int)target->query("mana_factor");
     damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/2, target);

                        me->improve_skill("gouhunshu", 1, 1);
       }
             }
   else
                msg += "$n见势头不好，于是闪身躲开了攻击。\n$N的元神又回到了$N的
身体里。\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "但是被$n躲开了。\n"--no report.

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}
