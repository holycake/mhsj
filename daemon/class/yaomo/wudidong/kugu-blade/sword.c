//Cracked by Roath

//刀光剑影

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;

      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (target->is_busy())
            return notify_fail("对方早就手忙脚乱了，放胆攻击吧！\n");
      if (me->query_skill("huntian-qigong",1)<50)
          return notify_fail("你的内功太差，还不会以剑法御刀。\n");
      if (me->query_skill("kugu-blade",1)<60) 
          return notify_fail("你还是先把精力集中在枯骨刀法上吧。\n");
    if(me->query("family/family_name") != "陷空山无底洞")
                return notify_fail("[刀光剑影]只有老鼠才能使用！\n");
        if (me->query_skill("qixiu-jian",1)<60)
        return notify_fail("你的七修剑法那么烂，还好意思夹在刀法中现眼？\n");
      if (me->query("force")<100)
           return notify_fail("你内力不继，难以出招。\n");
     
    me->add("force", -100);
  seteuid(getuid());
    me->set("actions", (: call_other, SKILL_D("qixiu-jian"), "query_action" :) );
   
    message_vision(HIB"$N突然间将手中"+weapon->name()+
       HIB"当做剑用，使出七修剑法，顿时攻了$n个措手不及！\n"NOR,me,target);
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","sword");
   enhance=me->query_skill("qixiu-jian",1);
    me->add_temp("apply/attack", enhance);  
  damage=me->query_skill("kugu-blade",1);
    damage=(damage+random(damage))/10;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target, weapon);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
    me->start_busy(random(2)+1);
    return 1;
}

