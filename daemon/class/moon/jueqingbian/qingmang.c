// qingmang.c
// edited by God for 2005.6
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");		
        if((int)me->query("max_force") < 2000)
		return notify_fail("你的内力修为不够。\n");
      	if((int)me->query("force") < 600 )
        	return notify_fail("你体内的内力不足！\n");
        if((int)me->query_skill("jueqingbian",1) < 200)
        	return notify_fail("你的『绝情鞭法』等级不够。\n");
        if((int)me->query_skill("moondance",1) < 200)
		return notify_fail("你的『冷月凝香舞』等级不够。\n");
	return 1;
}
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int skill, extra, time,damage;
        mapping style1= ([
			"action": HIG"$N"HIG"抖擞精神，身形一晃，一招"+HIC"「青盲」"+NOR+HIG"向$n"HIG"肩井穴划了过去，$n"HIG"眼睛一花，$w"HIG"的鞭锋已经堪然点到了$p身上！\n"NOR,
            		"dodge"	: -25,
			"parry"	: -65,                           
			"damage": 160,
			"force" : 50,
			"damage_type": "抽伤"          
        ]);     
        mapping style2= ([
        	"action": HIG"\n身形飘忽间$N"HIG"一个倒仰，一招"HIY"「青莽」"HIG"闪电般向$n"HIG"攒了过去，$n"HIG"大吃一惊，想要闪避已经不及，眨眼间$w"+HIG"就到了$p眉心之前！\n"NOR,
            	"dodge"	: -30,
            	"parry"	: -30,
            	"force"	: 60,
            	"damage": 170,       
            	"damage_type":       "刺伤"          
         ]);
	mapping style3= ([
        	"action": HIG"\n$N"HIG"一见前两招得手，洒手第三招"+NOR+HIC"「青芒」"+NOR+HIG"飞出，直向$n"HIG"心口而去，$n"HIG"已经被前两招丧光了胆，眼见这一鞭已经躲不开了！\n"NOR,
            	"dodge"	: -55,                           
            	"parry"	: -65,
            	"damage": 150,                           
            	"force"	: 70,
            	"damage_type":       "刺伤"
          ]);     
          
	if( !valid_perform(me) )
		return 0;	
          
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()           
         || target->is_corpse()
         || target==me || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招『青芒三式』？\n");

        weapon = me->query_temp("weapon");
        skill=(int)me->query_skill("jueqingbian",1);
        extra = (int)me->query_skill("moondance",1);
        damage = me->query_skill("whip");
        
        msg = HIG+"\n$N"+HIG+"身形一顿，将自身轻功发挥到极致，手中"+weapon->query("name")+HIG+"随意挥洒，飘忽难料，有如神助！\n"NOR;
        message_vision(msg,me,target);
	me->add("force", -100);         
        me->add_temp("apply/attack",extra/10);
        
	msg =  HIG "长天中一声青啸，人影晃动，鞭影飘香！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage/5);

	msg =  HIG "\n雷鸣不只，仰天察看，却听是鞭风呼啸。乍然望去，好似龙腾翻越！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage/3);

	msg =  HIG "\n朗朗晴空，忽漫天青叶，不明所以，沾身惊现却是鞭芒点点！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage/2);

	if( (int)me->query_skill("jueqingbian",1)>250
         && (int)me->query_skill("whip",1)>250 )
	{
        	me->set("actions",style1);                      
            	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage);
	}
	if( (int)me->query_skill("jueqingbian",1)>255
         && (int)me->query_skill("whip",1)>255 )
	{	            	
            	me->set("actions",style2);                      
            	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage);
	}
	if( (int)me->query_skill("jueqingbian",1)>300
         && (int)me->query_skill("whip",1)>300 )
	{            	
		me->set("actions",style3);                      
            	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage);
	}
	me->reset_action();                
	me->add_temp("apply/attack",-extra/10);
  	me->start_busy(2);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：青芒三式
        外功所属：绝情鞭法
        外功效果：对敌连续进行三次攻击，打击对方气血前后限
        	  外功需求技能达250级增加1次攻击
        	  外功需求技能达255级增加1次攻击
        	  外功需求技能达300级增加1次攻击
                  使用后自身busy 2 秒
        外功条件：
        	  人物等级25级
        	  内力修为二十年	
                  内力600点，消耗100点
                  绝情鞭法   200 级
                  冷月凝香舞 200 级
                  
STR;
        me->start_more(str);
        return 1;
}
