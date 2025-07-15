#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
	if(me->query("family/family_name") != "月宫")
		return notify_fail("「长恨天歌」是月宫不传之密！\n");
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");	
	if( userp(me) && me->is_knowing("moon_chimeng")!=2 )
		return notify_fail("你与痴梦无缘,领悟不到鞭法的精髓。\n");			
	if((int)me->query("max_force") < 2000 )
		return notify_fail("你的内力不够！\n");
	if((int)me->query("force") < 400 )
		return notify_fail("你的内力不足！\n");
	if((int)me->query_skill("jueqingbian", 1)<200)
		return notify_fail("你的绝情鞭法不够熟练，使用这一招会有困难！\n");
	if( me->query_skill_mapped("whip")!="jueqingbian" )
		return notify_fail("「长恨天歌」是绝情鞭的绝招。\n");		
	if(time()<me->query_temp("no_changhen")+5)
		return notify_fail("看你香汗淋漓的样子，等会儿再用吧！\n");
	return 1;	
}

int perform(object me, object target)
{
	int damage,int_damage,int_attack;
	string msg;
	object weapon;
	if( !valid_perform(me) )
		return 0;	
	if( !objectp(weapon=me->query_temp("weapon"))
	 || weapon->query("skill_type")!="whip" )
	 	return notify_fail("你的鞭子呢？\n");
			
	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me
	|| !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「长恨天歌」？\n");
	
	message_vision(HIW"\n$N"HIW"鞭法一变，茫茫离恨，万丈情劫席卷而来！~~~\n"NOR,me);
    	me->add("force", -50);
	me->set_temp("no_changhen",time());
	int_damage = me->query_temp("apply/combat_damage");
	int_attack = me->query_temp("apply/attack");

	if( me->query_temp("moon_huashen") && me->query_temp("moon_huashen")=="she" )
	{
		me->add_temp("apply/combat_damage",int_damage);
		me->add_temp("apply/attack",int_attack);
	}

	msg = HIC"\n夕殿萤飞思悄然，孤灯挑尽未成眠\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);

	msg = HIC"\n迟迟钟鼓初长夜，耿耿星河欲曙天\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);

	if((int)me->query_skill("jueqingbian", 1)>=250 )
	{
		me->add_temp("apply/combat_damage",int_damage);
		me->add_temp("apply/attack",int_attack);
		
		msg = HIC"\n鸳鸯瓦冷霜华重，翡翠衾寒谁与共\n"NOR;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	
		msg = HIC"\n悠悠生死别经年，魂魄不曾来入梦\n"NOR;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	}

	me->set_temp("apply/combat_damage",int_damage);
	me->set_temp("apply/attack",int_attack);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：长恨天歌
        外功所属：绝情鞭法
        外功效果：对敌连续进行二次攻击。
        	  外功需求技能达250级增加2次攻击
        	  化蛇状态下使用，攻击和命中翻倍
                  使用后冷却5秒
        外功条件：
                  月宫弟子
        	  人物等级20级
                  内力400点，消耗50点
                  绝情鞭法 200 级
                  
STR;
        me->start_more(str);
        return 1;
}
