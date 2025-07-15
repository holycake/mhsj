inherit SSERVER;

int cast(object me, object target)
{
	int wanying_time;
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能使用「万影迷踪」！\n");

	wanying_time=60+(200-(int)me->query_skill("spells"));
	if(wanying_time<60) wanying_time=60;
	if((time()-me->query("last_wanying"))<wanying_time)
		return notify_fail("你刚刚用过万影迷踪，再用此法，敌人也不会中着！\n");
	if( (int)me->query("mana") <4*(int)me->query_skill("spells"))
		return notify_fail("你的法力不够了！\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");

	message_vision("$N喃喃地念了几句咒语。\n", me);

	if( random(me->query("max_mana")) < 200 ) {
		me->add("mana",-(int)me->query_skill("spells"));
		me->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 1;
	}

	me->add("mana", -4*(int)me->query_skill("spells"));
	me->receive_damage("sen", 40);

	seteuid(getuid());
	soldier = new("/obj/npc/wsjiashen");

	soldier->move(environment(me));
	soldier->invocation(me);
	soldier->set_temp("invoker",me);
	me->set("last_wanying",time());
	me->start_busy(2+random(2));

	return 8+random(5);
}
