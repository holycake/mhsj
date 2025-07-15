//冷浸溶溶月
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
    	int damage;
    	object weapon,tweapon;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");    
	if( me->query("family/family_name")!="月宫" )
		return notify_fail("「冷浸溶溶月」乃是月宫的绝招！\n");
    	if( me->query_skill_mapped("whip")!="jueqingbian" )
		return notify_fail("「长恨天歌」是绝情鞭的绝招。\n");	
	if( userp(me) && me->is_knowing("moon_chimeng")!=2 )
		return notify_fail("你与痴梦无缘,领悟不到鞭法的精髓!!\n");
	if( !objectp(weapon=me->query_temp("weapon"))
	 || weapon->query("skill_type")!="whip" )
	 	return notify_fail("你的鞭子呢？\n");
   	if( me->query_skill("jueqingbian",1)<300 )
   		return notify_fail("你的绝情鞭法等级不够。\n");
	if((int)me->query("force")<400)
		return notify_fail("你的内力不够。\n"); 
   		
    	if( !target ) 
    		target = offensive_target(me);
    	if( !target
     	 || !target->is_character()
     	 || !me->is_fighting(target)
     	 || target->is_corpse()
     	 || target->is_ghost()
	 || target==me )
		return notify_fail("你要对谁施展这一招「冷浸溶溶月」？\n");


	me->add("force",-200);
        msg = HIC"$N"HIC"招式一变，手中$w"HIC"斜指向下，双眸露出漠然之色，一式「冷浸溶溶月」随心而出！\n"NOR;
        msg+= HIM"$N向前迈一步，平无华地挥出一鞭，慢，却噼啪作响。\n"NOR;
        succ_msg = HIR"$n"HIR"只觉得一股劲气象化作千百枚细针一样，穿体而过！“哇”的一声，喷出一大口鲜血，看来是受了内伤！\n"NOR;
        me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"小腹");
        me->delete_temp("pfm_msg");
        if( damage<1 )
        	message_combatd(HIC"$n"HIC"忙运功向抗，深厚的内力将$N"HIC"的漫天鞭影都激散了。\n"NOR,me,target);

	msg = HIM"\n$N"HIM"由静转动，一动便急如风，清歌曼影，鞭走奇招，每一鞭从$n"HIM"意想不到的方位无声无息地挥出！\n" NOR;
	succ_msg = HIR"$n"HIR"马上手忙脚乱，不知该如何去招架这静若幽冥、快如风的鞭法！果不然，$w"HIR"招招命中，$n"HIR"浑身上下被抽得遍体鳞伤！\n"NOR;
	damage = me->query_skill("whip");
	me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"小腹",damage);
        me->delete_temp("pfm_msg");
        if( damage<1 )
        	message_combatd(HIC"$n"HIC"却心静如水，丝毫不显慌乱，见招拆招，瓦解了$P这无声的攻势。\n"NOR,me,target);

	msg = HIM"\n$N"HIM"突然收住身形，回步而立，$w"HIM"收于背后，太阴之气弥漫，无招胜有招，无形胜有形。\n"NOR;
	succ_msg = HIR"$n"HIR"果然上当，急忙上前想抢攻。$N"HIR"微微一笑，待$p靠近，长袖一抖，袖尽影出，直探$p的胸口。$n"HIR"连鞭影还没看到，就差点儿被穿的透心凉！\n"NOR;
	damage = me->query_skill("whip")*2;
	me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,damage);
        me->delete_temp("pfm_msg");
        if( damage<1 )
        {
		message_combatd(HIC"$n"HIC"看破了这招的虚实，将计就计，却在$N"HIC"出招的一瞬间腾空而起，回手竟反攻一招！\n"NOR,me,target);
          	COMBAT_D->do_attack(target, me, target->query_temp("weapon"),TYPE_QUICK);
	}
	me->start_busy(2);
    	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：冷浸溶溶月
        外功所属：绝情鞭
        外功效果：连续攻击对方三次，可能造成对方内力的流逝
                  自身busy 2 秒
        外功条件：
        	  月宫痴梦弟子
        	  人物等级30级
                  内力400点，基本消耗200点
                  绝情鞭 300 级
                  
STR;
        me->start_more(str);
        return 1;
}