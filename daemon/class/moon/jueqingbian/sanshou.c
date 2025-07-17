//三无三不手 痴梦仙姑
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me)
{
	if( !me )
		return;
        message_vision(HIM"$N"HIM"心头一酸,一颗泪珠滴了下来。\n"NOR, me);
        me->delete_temp("JQB_perform");
	me->set_temp("JQB_end",time());		
}

int valid_perform(object me)
{
	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if( time()-(int)me->query_temp("wuxue_end") < 6 )
		return notify_fail("绝招用多就不灵了！\n");
	if(me->query_temp("JQB_perform")) 
		return notify_fail("你已经使出「三无三不手」了！\n");
	if((int)me->query("force") < 600 )
		return notify_fail("你的内力不足！\n");
	if( userp(me) && me->is_knowing("moon_chimeng")!=2 )
		return notify_fail("你与痴梦无缘,领悟不到鞭法的精髓!!\n");
	if((int)me->query_skill("jueqingbian",1) <400)
		return notify_fail("你的绝情鞭级别还不够施展这一招三无三不手!!\n");
	if((int)me->query_skill("moondance",1) <400)
		return notify_fail("你的冷月凝香舞等级不够!!\n");
	if( time()<(int)me->query_temp("JQB_end")+5 )
		return notify_fail("看你香汗淋漓的样子，等会儿再用吧！\n");
	return 1;	
}

int perform(object me, object target)
{
	object weapon;
	int skill,tt;
	string msg;

	if( !valid_perform(me) )
		return 0;	
	
	if( !target ) target = offensive_target(me);
	
	weapon = me->query_temp("weapon");
	msg = HIC"\n问世间情为何物?直叫人生死相许!$N"HIC"心中一阵酸楚，鞭法忽然变得灵动异常！\n" NOR;
	message_vision(msg, me, target);
	me->add("force", -50);
	me->set_temp("wuxue_end",time());
	
	if( target && me!=target && me->is_fighting(target) )
	{
		me->set_temp("JQB_perform",1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->is_knowing("moon_sanshou")*5);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->is_knowing("moon_sanshou")*5);
		if( (int)me->query_skill("jueqingbian",1)>=310 && me->query("force")>100 )
		{
			me->add("force", -50);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->is_knowing("moon_sanshou")*6);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->is_knowing("moon_sanshou")*6);
		}
		if( (int)me->query_skill("jueqingbian",1)>=350 && me->query("force")>100 )
		{	
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->is_knowing("moon_sanshou")*7);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->is_knowing("moon_sanshou")*7);
		}
		if( ( me->is_knowing("moon_sanshou") || !userp(me) )
		&& target && me->is_fighting(target)
		&& time()>target->query_temp("no_exert/start")+120 )
		{
			message_vision(HIG"\n$n"HIG"脑中抚不去$N"HIG"的身影，只觉心中一阵酸楚，内息忽地变得杂乱无章，不能凝聚起来。\n"NOR,me,target);	   
			target->set_temp("no_exert",([
				"start" : time(),
				"time"  : 15,
				"msg"   : HIG"\n你脑中抚不去"+me->name()+HIG"的身影，只觉心中一阵酸楚，内息忽地变得杂乱无章，不能凝聚起来。\n"NOR,    
			]));    
		} 
	}		
	me->set_temp("JQB_perform",1);
	if( me )
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), (int)me->query_skill("jueqingbian",1));
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：三无三不手
        外功所属：绝情鞭
        外功效果：将绝情鞭法转入三无三不手状态
        	  如果战斗中使用，则随之对敌进行连续两次攻击
        	  内力充沛的情况下，绝情鞭法达310级增加2次攻击，内力消耗增加50点
        	  内力充沛的情况下，绝情鞭法达350级增加2次攻击，内力消耗增加50点
        	  如领悟了三无三不手真谛，则会封住对手内息15秒
        	  可通过战斗中领悟来提高三无三不手的威力
                  状态停止后冷却5秒
        外功条件：
        	  月宫痴梦弟子
        	  人物等级40级
                  内力600点，基本消耗50点
                  绝情鞭 400 级
                  冷月凝香舞 400 级
                  
STR;
        me->start_more(str);
        return 1;
}
