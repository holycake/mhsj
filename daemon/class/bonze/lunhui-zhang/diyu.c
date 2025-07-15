#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,damage;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if(me->query("family/family_name")!="南海普陀山")
           return notify_fail("“我入地域”只有普陀山弟子才可以用！\n");
             if((int)me->query("max_force") < 800 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不足！\n");
//	if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "staff")
//                return notify_fail("你所使用的外功中没有这种功能。\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("buddhism", 1) < 60)
        	return notify_fail("你的大成佛法等级不够，不能使用这一招！\n");
	i=(int)me->query_skill("lunhui-zhang",1)+me->query_skill("staff",1)/2;
	j=(int)me->query_skill("lunhui-zhang",1);
        if(i<60 || j<1)        
                return notify_fail("你的轮回杖级别还不够，使用这一招会有困难！\n");
	
        me->delete("env/brief_message");
	target->delete("env/brief_message");
message_vision(HIY"\n$N口诵佛号，将全身功力注入手中"+weapon->name()+NOR+HIY"顿时间霞光四射，照得$n睁不开眼！\n\n"NOR,me,target);
	damage=me->query_skill("buddhism")/2 + me->query_skill("staff")/2 + me->query_skill("lunhui-zhang") + me->query("max_force");
	target->receive_damage("kee",damage/15);
	me->receive_damage("sen", 100);
        me->add("force", -200);
	me->receive_damage("kee", damage/10+random(3));
                COMBAT_D->report_status(target);
                COMBAT_D->report_status(me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}

   
