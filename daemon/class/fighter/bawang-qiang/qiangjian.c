// 枪里加锏

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object weapon1, weapon2;

	if(!target) target = offensive_target(me);

	if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「枪里加锏」？\n");

	if(!me->is_fighting())
                return notify_fail("「枪里加锏」只能在战斗中使用！\n");

	if((int)me->query("max_force") < 200)
		return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不足！\n");

	if((int)me->query("sen") < 250)
		return notify_fail("你的精神不足，没法子施用外功！\n");

	if((int)me->query_skill("bawang-qiang",1) < 100)
		return notify_fail("你的霸王枪级别还不够，使用这一招会有困难!\n");

	if((int)me->query_skill("wusi-mace",1) < 100)
		return notify_fail("你的无私锏级别还不够，使用这一招会有困难!\n");

	weapon1=me->query_temp("weapon");
	weapon2=present("mace", me);
	if(!objectp(weapon2)) 
		return notify_fail("没锏怎么枪里加锏?\n");

	message_vision(HIC"\n$N运足精神，抖手刺出一枪!\n"NOR, me, target);

	me->set_temp("BWQ_perform", 1);
	COMBAT_D->do_attack(me, target, weapon1);

	message_vision(HIC"\n趁着$n正忙于招架，$N抽出"+weapon2->query("name")+"击出两下"NOR, me, target);

	weapon1->unequip();
	weapon2->wield();

	me->set_temp("BWQ_perform", 2);
	COMBAT_D->do_attack(me, target, weapon2);

	me->set_temp("BWQ_perform", 3);
	COMBAT_D->do_attack(me, target, weapon2);

	me->delete_temp("BWQ_perform");

	me->receive_damage("sen", 100);
	me->add("force", -100);

	if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	weapon2->unequip();
	weapon1->wield();

        me->start_busy(1);

        return 1;
}

