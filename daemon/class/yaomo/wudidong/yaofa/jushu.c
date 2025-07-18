// jushu.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail(HIR "你要变巨鼠咬谁？\n"NOR);

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail(HIR "你的法力不够，无法变身为巨鼠！\n"NOR);

	if((int)me->query("sen") < 20 )
		return notify_fail(HIR "你无法集中精力，别被自己咬到！\n"NOR);

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write(HIC "Oh，Mygod！老鼠出去偷东西去了！\n");
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
		HIM "$N嘿嘿的奸笑了两声，跳到半空，变成一只青面獠牙的金皮巨鼠，张开血盆大口，
呼！地一声向$n张口咬去！\n" NOR,
			//initial message
		HIY "结果咬个正着，差点没把$n咬死！\n" NOR, 
			//success message
		HIR "但是$n在千钧一发之际躲了开来。\n" NOR, 
			//fail message
		HIW "但是金皮巨鼠被$n以法力一引，反而咬到了$N的面门！\n" NOR, 
			//backfire initial message
		HIW "结果咬个正着，差点没把$n咬死！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(0));
	return 1+random(2);
}

