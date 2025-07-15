#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 100;
	damage_adj = 100;

	if( !target ) target = offensive_target(me);


        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("你要对谁用道家仙火？\n");

        if((int)me->query_skill("wudang-spells", 1) < 50 )
                return notify_fail("你的武当法术火候不够，哪里喷得出仙火！\n");

        if((int)me->query("mana") < 300+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够，喷出的仙火恐怕没有什么用！\n");
/*
        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不够，无法将仙火喷出。\n");
*/
        if((int)me->query("sen") < 10 )
                return notify_fail("你现在神智不清，别把自己烧伤了！\n");

	me->add("mana", -400-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 200 ) {
		message_vision(HIM"$N口中念念有词。。。但什么也没有发生！\n"NOR,me);
		return 1;
	}
	
	me->receive_wound("kee", 10);

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"qi", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both/90"
HIC "$N突然走了一个八卦步，$n顿时被$N给迷惑住了。\n" NOR,
			//initial message
HIC "$N手中出来一道仙火将$n围住，只见$n在烈焰中挣扎。\n" NOR,
			//success message
HIC"\n忽然从$N的手中出来一道仙火将$n围住，。\n"NOR,
			//fail message
HIC "只见$n十分冷静的纵身一跃,躲过了$N的仙火。\n" NOR,
			//backfire initial message
HIR"\n$N手中出来一道仙火将$n围住，只见$n在烈焰中挣扎。\n" NOR,
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1);
}

