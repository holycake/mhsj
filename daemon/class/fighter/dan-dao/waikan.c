#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        mapping action;
 
        if (! target) target = offensive_target(me);
/*
        if (userp(me) && ! me->query("can_perform/dan-dao/waikan"))
                return notify_fail("你现在还不会使用「外看刀势」！\n");
*/
        if (! target || ! me->is_fighting(target))
                return notify_fail("「外看刀势」只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
		    || ((string)weapon->query("skill_type") != "blade"
		    && (string)weapon->query("skill_type") != "stick"
		    && (string)weapon->query("skill_type") != "spear"))
                return notify_fail("你使用的武器不对。\n");

        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，不能使用「外看刀势」！\n");

        if (me->query_skill("dan-dao", 1) < 100)
                return notify_fail("你的双手刀法修为不够，目前不能使用「外看刀势」！\n");

        if (me->query("neili") < 250)
                return notify_fail("你的真气不够，不能使用「外看刀势」！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW"$N使出"+HIR+"「外看刀势」"+HIW+"，开右边门户，进右脚于左，用" + weapon->name() +HIW"往右推防御$n的攻击。左脚右脚偷步滚身跳进$n的圈内。\n" NOR;

        ap = me->query_skill("blade");
        ap += me->query_skill("stick");
        ap += me->query_skill("spear");
        dp = target->query_skill("parry");
        action = me->query_action();

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                me->add("neili", -180);
                target->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$P再进左脚，横靠一刀。\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$P又进右脚，往右一搅，复砍一刀。\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$P再进左脚，横劈一刀。\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
        } else
        {
                me->add("neili", -60);
                msg = CYN "可是$p" CYN "奋力格挡，$P" CYN 
                       "只觉得精力略有衰竭，手中刀光渐缓。 \n" NOR;
                message_combatd(msg, me, target);
        }

        return 1;
}
