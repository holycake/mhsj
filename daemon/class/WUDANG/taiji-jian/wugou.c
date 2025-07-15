// wugou.c 天下无狗
// shang 97/6

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
	object *ob;
	int i, skill, damage;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("force") < 2000 )
		return notify_fail("你内力不雄厚不能使用天下无狗攻击。\n");

	if( (int)me->query("force") < 500 )
                return notify_fail("你现在没有足够的内力使用天下无狗。\n");

        if ((int)me->query("kee") < 100)
                return notify_fail("你现在没有足够的精力使用天下无狗。\n");

        if( (int)me->query_skill("taiji-jian", 1) < 200 )
                return notify_fail("你的打狗棒法火侯还没到，天下无狗使不出来。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

	skill = me->query_skill("taiji-jian", 1);

	me->add("force", -300);
	me->receive_damage("kee", 20);

	me->start_busy(2);
	message_vision(
		HIY "$N使出「天下无狗」的第六变，刹时四面八方是棒，。\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;

                damage = (int)me->query_skill("taiji-jian", 1);
                damage = (int)me->query_skill("taiji-jian", 1) +damage;
                damage = random(damage)+500;
		if( damage > 2000 ) damage = 2001;
		ob[i]->receive_damage("kee", damage , me);
		ob[i]->receive_damage("kee", damage / 5 , me);
		tell_object(ob[i], "你觉得眼前一阵棒雨，挨了不少下。\n");	
	        if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);}

	return 1;
}

	