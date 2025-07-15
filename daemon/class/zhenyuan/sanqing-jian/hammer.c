//Cracked by Roath

//刀光剑影

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void end_pfm(object me, int enhance,int damage,object weapon);

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage,howlong;

      if (!weapon) return 0;
      if (me->query_temp("wzg-powerup"))
        return notify_fail("小心走火入魔！\n");
      if (!me->is_fighting())
             return notify_fail("你没有在打架！\n");
      if (me->query_skill("zhenyuan-force",1)<80)
          return notify_fail("你的内功太差，还不能以剑作锤。\n");
      if (me->query_skill("sanqing-jian",1)<80) 
          return notify_fail("你还是先把精力集中在剑法上吧。\n");
    if (me->query_skill("kaishan-chui",1)<80)
        return notify_fail("你的开山锤太差劲了。\n");
      if (me->query("force")<200)
           return notify_fail("你内力不继，难以出招。\n");
     
    me->add("force", -200);
   
    message_vision(HIY"$N舞动手中"+weapon->name()+
     HIY"，以剑作锤，使出开山锤法，怪招迭出，把对手看得眼花缭乱，目瞪口呆！\n"NOR,me);
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set_temp("original/skill_type2",weapon->query("skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","hammer");
    weapon->set("skill_type","hammer");

  enhance=me->query_skill("sword")/3;
    me->add_temp("apply/attack", enhance);  
    damage=weapon->query("weapon_prop/damage");
    me->add_temp("apply/damage",damage);        
    howlong=me->query_skill("sanqing-jian")/10+4;
    me->start_busy(random(2));
    me->set_temp("wzg-powerup", 1);
    me->delete_temp("wzg_pfm_cleared");
    me->reset_action();
    call_out("remove_effect",howlong,me,enhance,damage,weapon);
    call_out("end_pfm",2,me,enhance,damage,weapon);

//    me->start_call_out( (: call_other, __FILE__, "end_pfm", 
//           me, enhance,damage,weapon:), 2);

    return 1;
}

void remove_effect(object me,int enhance,int damage,object weapon) {
    me->delete_temp("wzg-powerup");
    end_pfm(me,enhance,damage,weapon);
}
 
void end_pfm(object me, int enhance,int damage,object weapon)
{
    if (me->query_temp("wzg-powerup") &&
        me->query_temp("weapon")==weapon) {
          call_out("end_pfm",2,me,enhance,damage,weapon);
          return;
    }
    if (me->query_temp("wzg_pfm_cleared")) return;

    if (weapon) {
      weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
      weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
      weapon->set("skill_type",weapon->query_temp("original/skill_type2"));
    }
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("wzg-powerup");
    me->set_temp("wzg_pfm_cleared",1); // make sure only remove effect once.
    me->reset_action();
}

