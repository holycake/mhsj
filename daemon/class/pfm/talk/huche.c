

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;
	
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「胡扯」只有在战斗中才能使用。\n");

	if( (int)me->query_skill("talk", 1) < 50 ) 
		return notify_fail("你的修为不够深，还使不出这一招！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"已经够忙了，你说的再漂亮也不会注意到。\n");

	message_vision(HIW"$N张开大嘴，人是人他妈生的，妖是妖他妈生的，$n你妈贵姓！\n\n"NOR,me, target);

	mypot=(int)me->query_skill("literate");
	if(mypot >100)mypot =3;
	if(mypot >200)mypot =2;

	
        if ( random(5) > mypot ) {
                message_vision(HIR"$N傻傻望着你，突然血气翻涌，哇！的吐出一口鲜血！\n"NOR,target);
                target->set("kee",-1);
		  //me->set("kee",0);
	}else {
	message_vision(HIR"$N点都不点，我早听过你唧唧歪歪，看！我耳朵堵上了！\n"NOR,target,
me);
                //me->start_busy(5+random(5));
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}

