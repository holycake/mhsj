#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, force;

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("安全区内不能引动九天灵气！\n");
        if( !me->is_fighting() )
                return notify_fail("倒转乾坤只能在战斗中使用。\n");
        if( me->query("family/family_name")!="武圣门")
                return notify_fail("不是武圣门的不能用「倒转乾坤」！\n");
        if( (int)me->query("force") < 400 )
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了。\n");
        if( (int)me->query_skill("xiantian", 1) < 290)
                return notify_fail("你的先天乾坤功修为还不够，使用这一招会有困难！\n");
                
        skill = me->query_skill("force");
	force = me->query("max_force");
        me->add("force", -350);
        me->receive_damage("kee", 150);

        me->start_busy(5);
	message_vision(HIR "\n$N飞身而上，屏气凝神，双手对天一指，引动出九天灵气归于己用！\n顿时天昏地暗，日月无光，天地颠倒！\n好一招灭绝众生的「倒转乾坤」！\n\n"
NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = ( skill + force) * 10 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("sen", damage, me);
                        if( (int)ob[i]->query("force") < skill * 2 )
                        ob[i]->receive_wound("sen", damage/10, me);
                        tell_object(ob[i], "你觉得眼前一阵金星乱冒，浑身痛得像是要裂开一样！\n");
                }
		COMBAT_D->report_sen_status(ob[i]);		
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}

