#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        mapping action;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);
/*
        if (userp(me) && ! me->query("can_perform/dan-dao/yingtui"))
                return notify_fail("你现在还不会使用「迎推刀势」！\n");
*/
        if (! target || ! me->is_fighting(target))
                return notify_fail("「迎推刀势」只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
		    || ((string)weapon->query("skill_type") != "blade"
		    && (string)weapon->query("skill_type") != "stick"
		    && (string)weapon->query("skill_type") != "spear"))
                return notify_fail("你使用的武器不对。\n");

        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，不能使用「迎推刀势」！\n");

        if (me->query_skill("dan-dao", 1) < 100)
                return notify_fail("你的双手刀法修为不够，目前不能使用「迎推刀势」！\n");

        if (me->query("neili") < 250)
                return notify_fail("你的真气不够，不能使用「迎推刀势」！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW"$N使出"+HIR+"「迎推刀势」"+HIW+"，先立外看势，开右边门户，饵$n来攻。$n见机会难得，正面直击$N。\n孰料$N略偷左脚于右，转身砍击$n。" NOR;

        ap = me->query_skill("blade");
        ap += me->query_skill("stick");
        ap += me->query_skill("spear");
        dp = target->query_skill("parry");
        action = me->query_action();

        if (ap / 2 + random(ap) > dp)
        {
        	damage = ap / 2 + random(ap / 2);
        	if (! objectp(ob = target->query_temp("weapon")))
        	{
                me->add("neili", -180);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
            }
            else
            {
	        	message_vision(HIW "$N只觉得手中" + ob->name() + "把持不定，脱手飞出！\n" NOR,
				target);
				ob->unequip();
				ob->move(environment(target));
				target->reset_action();
/*	            	message_vision(HIW "只听见「啪」地一声，$N手中的" + ob->name()
				+ "已经断为两截！\n" NOR, ! ob->is_item_make() );
				ob->unequip();
				ob->move(environment(target));
				ob->set("name", "断掉的" + ob->query("name"));
				ob->set("value", 0);
				ob->set("weapon_prop", 0);
				target->reset_action();*/
			}
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "奋力格挡，$P" CYN 
                       "只觉得精力略有衰竭，手中刀光渐缓。 \n" NOR;
                message_combatd(msg, me, target);
        }

        return 1;
}
