#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,anqi;
        string msg;
        int ap, dp;
        int damage, i, j=0;
        mapping action;
        string *allow_wp = ({"blade", "stick", "spear"});
 
        if (! target) target = offensive_target(me);
/*
        if (userp(me) && ! me->query("can_perform/dan-dao/feidao"))
                return notify_fail("你现在还不会使用「飞刀势」！\n");
*/
        if (! target || ! me->is_fighting(target))
                return notify_fail("「飞刀势」只能在战斗中对对手使用。\n");

		if (! objectp(weapon = me->query_temp("weapon"))
		    || ((string)weapon->query("skill_type") != "blade"
		    && (string)weapon->query("skill_type") != "stick"
		    && (string)weapon->query("skill_type") != "spear"))
                return notify_fail("你使用的武器不对。\n");

        if (! objectp(anqi = me->query_temp("handing")) ||
            (string)anqi->query("skill_type") != "throwing" ||
            anqi->query_amount() < 1)
                return notify_fail("你手中必须先有暗器。\n");

        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，不能使用「飞刀势」！\n");

        if (me->query_skill("dan-dao", 1) < 100)
                return notify_fail("你的双手刀法修为不够，目前不能使用「飞刀势」！\n");

        if (me->query("neili") < 250)
                return notify_fail("你的真气不够，不能使用「飞刀势」！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW"$N使出"+HIR+"「飞刀势」"+HIW+"，将暗器飞刺而去，$n急忙招架。\n" NOR;
		anqi->add_amount(-1);

        ap = me->query_skill("blade");
        ap += me->query_skill("stick");
        ap += me->query_skill("spear");
        ap += me->query_skill("throwing");
        ap += me->query_skill("dagger");
        dp = target->query_skill("parry");
        action = me->query_action();

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                me->add("neili", -10);
                target->start_busy(3);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 60,
                                           HIR "结果$p" HIR "被$P" HIR "攻了个措手不及，中了暗器！\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
        }
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                me->add("neili", -180);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$P乘此之机，用" + weapon->name() +"砍入，好一个短技长用！\n" NOR );
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
