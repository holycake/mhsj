#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;
            int i;
	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展这一招「真武七绝阵」？\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

        if(!me->is_fighting())
                return notify_fail("「真武七绝阵」只能在战斗中使用！\n");

	if((int)me->query("sen") < 300 )
		return notify_fail("你的精神不足，没法子施用外功！\n");

              i=(int)me->query_skill("wudang-spells",1)+(int)me->query_kar();

        if( i < 50)
                return notify_fail("你的武当仙法别还不够，使用这一招会有困难！\n");

	me->add("mana", -100-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 250);

	if( random(me->query("max_mana")) < 50 ) {
		write("好象没反应，再来一次吧！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both/70"
		HIC "$N大吼一声：布阵\n一个北斗七星阵势摆在$N眼前！\n" NOR,
			//initial message
              HIC  "突然看见有七个人影向$n飞去！\n"  NOR,
			//success message
		HIC "但是$n在千钧一发之际躲了开来。\n" NOR, 
			//fail message
		HIC "但是真武七绝阵被$n以法力一引，反而劈向了$N的！\n" NOR, 
			//backfire initial message
		HIC "结果被真武七绝阵围住，差点没把$n劈成两半！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1);
	return 3+random(5);
}

