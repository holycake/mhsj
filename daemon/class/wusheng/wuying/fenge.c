#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int mypot,tapot,damage_pot,damage;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「分割天地」？\n");

        if(!me->is_fighting())
                return notify_fail("「分割天地」只能在战斗中使用！\n");
        if(me->query("family/family_name")!="武圣门")
                return notify_fail("不是武圣门的不能用「分割天地」！\n");
        if((int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("feisheng", 1) < 50)
		return notify_fail("你的飞升大法等级不够，不能使用这一招！\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIY"\n$N闭上双目，使出一招「分割天地」，手中"+NOR+HIW+weapon->name()+NOR+HIY"金光四射，腾空飞起直斩$n！\n\n"NOR,me,target);

	mypot=(int)me->query_skill("sword");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));
	
        tapot=((int)target->query_skill("dodge")+(int)target->query_skill("parry"))/2;
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));      
        
        damage_pot=(int)me->query_skill("wuying");           
        
	if ( random(mypot) > random(tapot) )
	
	{
	  target->receive_damage("kee",damage);
	  me->receive_damage("sen", 100);
          me->add("force", -100);
          me->start_busy(1); 
          COMBAT_D->report_status(target);
        
          if( !target->is_fighting(me) ) 
        	{
                	if( living(target) ) 
                	{
                        	if( userp(target) ) target->fight_ob(me);
                        	else target->kill_ob(me);
                	}
        	}
	}
	
	else
	{
	 	message_vision(HIW"\n$n连闪了几下好不容易躲开了这几道剑光！\n\n"NOR,me,target);
                me->start_busy(2);
 	}
        return 1;
}

   
