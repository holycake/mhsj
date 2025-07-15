//bingpo-blade
//by mhsj@gslxz 2001/7/12
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
                object weapon;
        int bingpo,times;
        string shu,str;
        bingpo = (int)me->query_skill("bingpo-blade", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(HIW"你要对谁施展这一招"HIM"「暴雪风沙」"HIW"？\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIM"「暴雪风沙」"HIW"只能在战斗中使用！\n"NOR);
         
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="blade")
                return notify_fail(HIM"冰魄寒刀"HIW"要用刀才能发挥威力。\n"NOR);

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 300 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail(HIW"你的精神不足，施展"HIM"「暴雪风沙」"HIW"会出人命的！\n"NOR);

        if(bingpo < 40)
                return notify_fail(WHT"你的冰魄寒刀级别还不够。\n"NOR);
        else 
            if(bingpo <70){
                times = 3;        
                shu = "三";}
            else
                if (bingpo <100){
                    times = 4;
                    shu = "四";}
                else 
                    if( bingpo<130){
                        times = 5;
                        shu = "五";}
                    else
                        if(bingpo <160 ){
                           times = 6;
                           shu = "六";}
                        else 
                            if (bingpo < 190){
                               times = 7;
                               shu = "七";}
                            else
                                if (bingpo < 220){
                                    times = 8;
                                    shu = "八";}
                                else{ 
                                     times = 9;
                                     shu = "九";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");


message_vision(HIC"\n$N一声长啸，刀光一转，有如帮风雪般的向$n扑来，只见$N连续向$n劈出了"+shu+"刀，刀刀致命！\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
       	    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"被"+me->name()+HIM"用大雪山绝招"HIW"「暴雪风沙」"HIM"杀死了，听说尸体已经冻得不成人形了！";
	                 message("channel:rumor",HIM"〖无中生有〗某人："+str+"\n"NOR,users());
	               }
 
        me->receive_damage("sen", 20);
        me->add("force", -(times*50+150));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

