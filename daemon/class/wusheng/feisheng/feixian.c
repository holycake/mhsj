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
		return notify_fail("你要对谁施展「天外飞仙」？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("你无法集中精力瞄准！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("叶孤城说你比剑输了给他，他不来了！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
		target, 
		success_adj, 	
		damage_adj, 	
		"both", 		
		HIC "$N口中念了几句咒文，随着一声“叶孤城在此！”半空中现出一位气宇轩昂的侠士。\n只见他双手祭剑，“嗖”的一声，一股令人窒息的剑气向$n激射而下！\n" NOR,
		HIC "结果剑气从$n身上透体而过，顿时血花飞溅！\n" NOR, 
		HIC "只见$n轻轻一跳，剑气正好于$n擦身而过！\n" NOR, 
                HIC "但是$n以法力一拨，剑气“嗖”的一声折向$N！\n" NOR,

		HIC "结果剑气从$n身上透体而过，顿时血花飞溅！\n" NOR
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

