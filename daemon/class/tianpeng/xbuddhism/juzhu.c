// juzhu.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 100;
	damage_adj = 100;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展巨猪？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("你无法集中精力变成巨猪！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write(WHT"巨猪昨天吃的不好，正在家闹肚子，来不了了！\n"NOR);
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
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "只见$N变成一头巨猪，张着大口向$n扑来！\n" NOR,
			//initial message
		HIC "结果$n被巨猪压个正着，只听“嘎嘣”一\n声，好像$n的骨头断了！\n" NOR, 
			//success message
		HIC "只见$n就地打了一个滚，巨猪正好压在$n脚上！\n" NOR, 
			//fail message
        HIC "但是巨猪被$n的法力所逼，巨猪向着$N压了过来！\n" NOR,
			//backfire initial message
		HIC "结果$n被巨猪压个正着，只听“嘎嘣”一声，好像\n$n的骨头断了！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

