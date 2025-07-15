
//我入地狱    dhxy-dragon 2000.4

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
void postdiyu(object,object,object,int);
void remove_effect(object);

int perform(object me, object target)
{
      int enhance,damage;
      object weapon=me->query_temp("weapon");
      mapping action;

      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (me->query_skill("force")<100)
          return notify_fail("你的内功太差。\n");
      if (me->query_skill("buddhism",1)<60)
         return notify_fail("你佛法不够，还没有入地狱的慈悲心肠。\n");
      if (damage=me->query_skill("staff")<100) 
          return notify_fail("你的杖法还欠火候。\n");
      if (me->query("force")<500)
           return notify_fail("你内力不继，难以出招。\n");
     
    if (me->query_temp("pfm_diyu_delay")) return notify_fail("你刚用过此招，还是先调整一下吧。\n");
  me->add("force",-200);
    message_vision(HIY"$N口诵佛号，将全身功力注入手中"+weapon->name()+
       HIY"顿时间霞光四射，照得$n睁不开眼！\n"NOR,me,target);
    enhance=me->query_skill("lotusforce",1)/2;
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("buddhism",1);
    if (damage>200) damage=200;
    action=copy(me->query("actions"));
    damage=action["damage"]*damage/20;
  if (wizardp(me)) write (damage+"\n");
    action["post_action"] = (: postdiyu :);
    me->add_temp("apply/damage",damage);
    me->set_temp("putuo_diyu",1);
    me->set("actions",action);
    COMBAT_D->do_attack(me, target, weapon);
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
    return 1;
}
//  diyu的使用时间
void postdiyu(object me,object target,object weapon,int damage) {
   int howlong=damage/100+1;

   me->start_busy(1);
   if (!me->query_temp("putuo_diyu")) return;
   me->delete_temp("putuo_diyu");
   if (damage<100) return;
   message_vision(HIR"$N用力过度，只觉得浑身虚脱，动弹不得。\n"NOR,me);
   damage=random(damage);
   if (me->query("kee")-damage<10) damage=me->query("kee")-10;
  if (damage<0) damage=0;
   me->receive_damage("kee",damage);
   COMBAT_D->report_status(me); 
  me->set_temp("pfm_diyu_delay",1);
  call_out("remove_effect",howlong,me);

  // 删掉set_temp
}
void remove_effect(object me){
  me->delete_temp("pfm_diyu_delay");
}
