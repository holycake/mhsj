
#include <ansi.h>
// inherit F_SSERVER;
inherit SSERVER;

#include "/daemon/skill/eff_msg.h";
int def;
int perform(object me, object target)
{       
        object weapon1;
        string msg;
        int damage, p,time;
if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「龙行天下」只能在战斗中使用。\n");
       if( !(weapon1 = me->query_temp("weapon"))
        ||      (string)weapon1->query("skill_type") != "hammer" )
                return notify_fail("你以为你是谁？没锤也发龙行天下！\n"); 
        if( (int)me->query_skill("hammer", 1) < 100 ||
           (int)me->query_skill("huntian-hammer", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用「龙行天下」。\n");
        if((int)me->query_skill("dodge", 1) <120)
return notify_fail("以你现在的轻功修为如何「龙行天下」。\n");
        if((int)me->query_skill("force", 1) <100)
return notify_fail("以你现在的内功修为还使不出「龙行天下」。\n");
        if( (int)me->query("max_force") < 1200 )
return notify_fail("以你现在的内功修为还使不出「龙行天下」。\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
        msg = HIY "\n$N使出龙宫终极绝技「龙行天下」，身法陡然加快！\n" NOR;
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3))
        {
                me->start_busy(2);
                target->start_busy(1);
msg += YEL "\n$N忽然猛一吸气，抡锤回舞，向$n轻轻地敲出。\n"NOR;
if (me->query("str") > random(target->query("str")))
                   {
        msg += HIR "\n但见$n大喝一声，以雄厚的内力震碎了你锤影所形成的气场！\n" NOR;
        msg += HIR "结果$n只来的急发出两、三招，就无法再维持澎湃的气势。\n" NOR;
                damage = (int)me->query_skill("huntian-hammer", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
               target->set_temp("last_damage_from", me);
                if(me->query_skill("hammer", 1) > 119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                    } else 
                {
        msg += HIC "初时似乎出手不重，但其波浪状的锤影后浪击前浪，一浪高过一浪，连绵不尽！\n"NOR;
        message_vision(msg, me, target);
for (p=1;p<3+random(3);p++)
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                if(random(me->query_skill("huntian-hammer", 1))> 119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                 }
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIG"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
 if(me->query_skill("huntian-hammer",1)>119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                 }
        message_vision(msg, me, target);
        }
        return 1;
}

// 第二击

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「龙行天下现在没对手了呀。\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
if (random(5)>2)
       msg = HIC"\n但见$N倒拖兵器,突然一个仰身,大喝一声,募的绕身回敲,$n眼前一黑!!\n"NOR;
else
        msg = HIG"\n但见$N倒拖兵器,突然狂啸一声,抡锤横扫,声势刚烈,$n早已吓慌了手脚!!\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
        {
       msg = CYN "$n惊骇之下，顿时出招散乱，无从招架！\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("huntian-hammer", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
              if(me->query_skill("huntian-hammer", 1) > 179)
                {
             remove_call_out("perform3");
                call_out("perform3", 0, me, target);    
                 }
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg = WHT"可是$p料敌之先,抢攻几招，反逼$N连连后退。\n"NOR;
                if(me->query_skill("huntian-hammer", 1) > 179
                && me->query_skill("hammer", 1) > 179)
                {
             remove_call_out("perform3");
                call_out("perform3", 0, me, target);    
                 }
        }
        message_vision(msg, me, target);
        return 1;
}


int perform3(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「龙行天下现在没对手了呀。\n");
        if( (int)me->query("force", 1) < 2000 )
                return notify_fail("你待要再出第四击，却发现自己的内力不够了！\n");     
if (random(5)>2)
    {
        msg = HIC"\n$N一声咆哮，兵器竟然脱手飞出，如游龙般翱翔青宇，破空射向$n的左肩！\n"NOR;
       msg += HIC "$n大吃一惊，但见$N空手猱身而上，双手擒拿点拍，攻势凌厉之极!\n" NOR;
     }
else 
        msg = HIG"\n$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道锤影，弥漫天际！\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3*2))
        {
       msg = CYN "$n慌乱中已经躲闪不及,$N抡起就是一锤\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
               //damage = damage*(1+random(3))/2+random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
               target->set_temp("last_damage_from", me);
                me->start_busy(2);
        } else 
        {       
              me->start_busy(1+random(2));
                me->add("force", -200);                
                msg = HIC"可是$p一个反身,轻轻躲过$N凌厉的进攻。\n"NOR;
        message_vision(msg, me, target);
        }
                me->add("force",-500);                
        return 1;
}
