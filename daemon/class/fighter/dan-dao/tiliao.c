#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage, i;
        mapping action;
 
        if (! target) target = offensive_target(me);
/*
        if (userp(me) && ! me->query("can_perform/dan-dao/tiliao"))
                return notify_fail("�����ڻ�����ʹ�á������õ��ơ���\n");
*/
        if (! target || ! me->is_fighting(target))
                return notify_fail("�������õ��ơ�ֻ����ս���жԶ���ʹ�á�\n");

		if (! objectp(weapon = me->query_temp("weapon"))
		    || ((string)weapon->query("skill_type") != "blade"
		    && (string)weapon->query("skill_type") != "stick"
		    && (string)weapon->query("skill_type") != "spear"))
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á������õ��ơ���\n");

        if (me->query_skill("dan-dao", 1) < 100)
                return notify_fail("���˫�ֵ�����Ϊ������Ŀǰ����ʹ�á������õ��ơ���\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʹ�á������õ��ơ���\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW"$Nʹ��"+HIR+"�������õ��ơ�"+HIW+"�����ұ��Ż�����$n������\n" NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("blade");
        ap += me->query_skill("stick");
        ap += me->query_skill("spear");
        dp = target->query_skill("parry");
        action = me->query_action();

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 2);
                me->add("neili", -180);
                target->start_busy(3);
                i=1+random(3);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIW "$N����" + weapon->name() +HIW"����б�ö��ϡ�\n" NOR );
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIW "$N���󲽸��������á�\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
                while (i--)
                {
                COMBAT_D->do_attack(me, target, weapon, 0);
            }
        } else
        {
                me->add("neili", -60);
                msg += CYN "����$p" CYN "�����񵲣�$P" CYN 
                       "ֻ���þ�������˥�ߣ����е��⽥���� \n" NOR;
                message_combatd(msg, me, target);
        }

        return 1;
}
