#include <ansi.h>

#include <skill.h>

inherit SSERVER;

int perform(object me, object target)

{

        int i,j,k,damage;

        if( !target ) target = offensive_target(me);

        if( !target

        ||      !target->is_character()

        ||      target->is_corpse()

        ||      target==me)

                return notify_fail("你要对谁使用夺魂掌？\n");

        if(!me->is_fighting())

                return notify_fail("你们没有在打架！\n");

        if((int)me->query("max_force") < 100 )

                return notify_fail("你的内功太差。\n");

        if((int)me->query("force") < 100 )

                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )

                return notify_fail("你的精神不足，没法子施用外功！\n");

	if((int)me->query_skill("jinghun-zhang", 1) < 40)

        	return notify_fail("你的惊魂掌等级不够，不能使用这一招！\n");

	i=(int)me->query("combat_exp");

       j=(int)target->query("combat_exp");

             k=(int)me->query_skill("jinghun-zhang");

        me->delete("env/brief_message");

	target->delete("env/brief_message");

message_vision(HIW"\n$N大喝道：哪命来。"NOR,me,target);

message_vision(HIW"\n一掌打向$n\n"NOR,me,target);

	if (random(i+j)>j) {

            damage=k+random(k);

target->receive_damage("kee",damage);

target->receive_wound("kee",damage/5);

target->start_busy(5);

             if (k>160) k=160;

target->apply_condition("hell_zhua",

(int)target->query_condition("hell_zhua")+2+k/20);

                COMBAT_D->report_status(target);

message_vision(CYN"\n$n身子一晃，只见背上留下了一个黑色的掌印！\n"NOR,me,target);

}

else message_vision(HIR"\n$n身子一闪，躲开了这一掌！\n"NOR,me,target);

me->receive_damage("sen", 30);

        me->add("force", -100);

	me->receive_damage("kee", 30);

 if( !target->is_fighting(me) ) {

                if( living(target) ) {

                        if( userp(target) ) target->fight_ob(me);

                        else target->kill_ob(me);

}

}

    me->start_busy(1);

return 1;

}

