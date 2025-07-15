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
                return notify_fail("�����ڻ�����ʹ�á��ɵ��ơ���\n");
*/
        if (! target || ! me->is_fighting(target))
                return notify_fail("���ɵ��ơ�ֻ����ս���жԶ���ʹ�á�\n");

		if (! objectp(weapon = me->query_temp("weapon"))
		    || ((string)weapon->query("skill_type") != "blade"
		    && (string)weapon->query("skill_type") != "stick"
		    && (string)weapon->query("skill_type") != "spear"))
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (! objectp(anqi = me->query_temp("handing")) ||
            (string)anqi->query("skill_type") != "throwing" ||
            anqi->query_amount() < 1)
                return notify_fail("�����б������а�����\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á��ɵ��ơ���\n");

        if (me->query_skill("dan-dao", 1) < 100)
                return notify_fail("���˫�ֵ�����Ϊ������Ŀǰ����ʹ�á��ɵ��ơ���\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʹ�á��ɵ��ơ���\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW"$Nʹ��"+HIR+"���ɵ��ơ�"+HIW+"���������ɴ̶�ȥ��$n��æ�мܡ�\n" NOR;
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
                                           HIR "���$p" HIR "��$P" HIR "���˸����ֲ��������˰�����\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
        }
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                me->add("neili", -180);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$P�˴�֮������" + weapon->name() +"���룬��һ���̼����ã�\n" NOR );
                message_combatd(msg, me, target, "",damage,action["damage_type"]);
        } else
        {
                me->add("neili", -60);
                msg = CYN "����$p" CYN "�����񵲣�$P" CYN 
                       "ֻ���þ�������˥�ߣ����е��⽥���� \n" NOR;
                message_combatd(msg, me, target);
        }

        return 1;
}
