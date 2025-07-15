
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
           int damage;
         string msg;
       object weapon;
    int skill;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「妖雾冲天」?\n");
        weapon = me->query_temp("weapon");
        if(!me->is_fighting())
                return notify_fail("「妖雾冲天」只能在战斗中使用!\n");

        if((int)me->query("max_force") < 1500)
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 500 )
     return notify_fail("你的内力不足！\n");


if (!weapon || weapon->query("skill_type") != "blade"  )
    return notify_fail("你必须在使用兵器时才能使用！\n");

        if((int)me->query_skill("bingpo-blade",1) < 120)
        return notify_fail("你的冰魄寒刀等级还不够!\n");

    msg = MAG
"\n$N阴阴一笑,手中的"+weapon->name()+""+MAG"轻轻一挥,登时飞沙走石,妖雾直冲天际!!\n"NOR;
message_vision(msg, me, target);
   me->delete("env/brief_message");
   target->delete("env/brief_message");
//     target->is_fighting("kee", damage/1);
  target->receive_wound("kee", damage/1);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         me->add("force", -150);
        target->apply_condition("bp_poison",5+random(5) + target->query_condition("bp_poison"));
    //    if( !target->is_fighting(me)) 
        if( !target->is_damage(me)/1) 
 // if(target->receive_wound("kee", damage/1));
{
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}

