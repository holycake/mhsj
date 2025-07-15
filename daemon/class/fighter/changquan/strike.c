//天女散花 
// dream 7/17/97
// modified by xlb 11/98

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「龙虎开道」？\n");

        /*if((int)me->query("force") < 15+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");*/
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("changquan", 1) <20)
                return notify_fail("你的长拳级别还不够！\n");

        if((int)me->query_skill("changquan", 1) >80)
                return notify_fail("你已不是新手，用这种招式有些丢面子！\n");

        //me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 10);
        msg = HIW"$N脚踏七星步，使出" + HIR + "「龙虎开道」" + HIW + "，"+
      "左拳虚引如龙游，右拳暴起似虎扑，拳风如雷，直逼$n而去！\n" NOR;

        ap = me->query_skill("changquan", 1);
        ap = ( ap * ap * ap / (1 * 200) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (1 * 200) );
        dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
                msg += HIC "谁知$n身形后仰，紧接着一个转身便让开了攻势。\n\n"NOR;
                message_vision(msg, me, target);
        } else {
		damage = (int)me->query_skill("changquan", 1) / 5 +
		         (int)me->query("sen") / 10 + random((int)me->query("sen") / 10) +
		         (int)me->query("kee") / 10 + random((int)me->query("kee") / 10);
		msg += HIR"$N一声暴喝，马步沉稳，右拳如山崩地裂砸向$n胸口！\n" NOR;
		target->receive_damage("sen", me->query("eff_sen") * damage / 70, me);
		target->receive_damage("kee", me->query("eff_kee") * damage / 100, me);
		me->improve_skill("changquan", 1, 1);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);

		// 第二段攻击
		damage = (int)me->query_skill("changquan", 1) / 5 +
		         (int)me->query("sen") / 10 + random((int)me->query("sen") / 10) +
		         (int)me->query("kee") / 10 + random((int)me->query("kee") / 10);
		msg = HIR"$N左拳紧随，横扫千军，劲风撕空，扫向$n腰际！\n" NOR;
		target->receive_damage("sen", me->query("eff_sen") * damage / 70, me);
		target->receive_damage("kee", me->query("eff_kee") * damage / 100, me);
		me->improve_skill("changquan", 1, 1);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);

		// 第三段攻击
		damage = (int)me->query_skill("changquan", 1) / 5 +
		         (int)me->query("sen") / 10 + random((int)me->query("sen") / 10) +
		         (int)me->query("kee") / 10 + random((int)me->query("kee") / 10);
		msg = HIR"$N骤然贴身，一式‘虎跃龙腾’，双拳并出，轰然砸向$n头颅！\n" NOR;
		target->receive_damage("sen", me->query("eff_sen") * damage / 70, me);
		target->receive_damage("kee", me->query("eff_kee") * damage / 100, me);
		me->improve_skill("changquan", 1, 1);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
         }


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(3);
        return 1;
}
