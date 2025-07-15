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
                return notify_fail("�����ڻ�����ʹ�á�ӭ�Ƶ��ơ���\n");
*/
        if (! target || ! me->is_fighting(target))
                return notify_fail("��ӭ�Ƶ��ơ�ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
		    || ((string)weapon->query("skill_type") != "blade"
		    && (string)weapon->query("skill_type") != "stick"
		    && (string)weapon->query("skill_type") != "spear"))
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á�ӭ�Ƶ��ơ���\n");

        if (me->query_skill("dan-dao", 1) < 100)
                return notify_fail("���˫�ֵ�����Ϊ������Ŀǰ����ʹ�á�ӭ�Ƶ��ơ���\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʹ�á�ӭ�Ƶ��ơ���\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW"$Nʹ��"+HIR+"��ӭ�Ƶ��ơ�"+HIW+"�������⿴�ƣ����ұ��Ż�����$n������$n�������ѵã�����ֱ��$N��\n����$N��͵������ң�ת����$n��" NOR;

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
	        	message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
				target);
				ob->unequip();
				ob->move(environment(target));
				target->reset_action();
/*	            	message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name()
				+ "�Ѿ���Ϊ���أ�\n" NOR, ! ob->is_item_make() );
				ob->unequip();
				ob->move(environment(target));
				ob->set("name", "�ϵ���" + ob->query("name"));
				ob->set("value", 0);
				ob->set("weapon_prop", 0);
				target->reset_action();*/
			}
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�����񵲣�$P" CYN 
                       "ֻ���þ�������˥�ߣ����е��⽥���� \n" NOR;
                message_combatd(msg, me, target);
        }

        return 1;
}
