#include <ansi.h>

#include <combat.h>

inherit SSERVER;

int perform(object me, object target)

{

 string msg;

int extra,lvl,lv;

 int i;

 object weapon;

 if( !target ) target = offensive_target(me);

 if( !target

 || !target->is_character()

 || !me->is_fighting(target) )

  return notify_fail("无边地狱只能对战斗中的对手使用。\n");

if(me->query("family/family_name")!="陷空山无底洞")

return notify_fail("“无边地狱”只有无底洞门人才可以用！\n");

 weapon = me->query_temp("weapon");

 if( (string)weapon->query("skill_type") != "blade" )

 return notify_fail("你手上无刀，不能使用无边地狱！\n");

 if( (int)me->query("force") <= 1000 )

 return notify_fail("你内力不够，不能使用无边地狱！\n");

 //if(me->query("force_factor")>100) 

 //   me->set("force_factor",100);

 extra = me->query_skill("kugu-blade",1) / 5;

 me->add_temp("apply/attack", extra);

 //me->add_temp("apply/damage", extra);^M

 msg = HIR  "$N使出［枯骨刀法］的无边地狱，手中的"+ weapon->name() +"斜斜劈出，$n顿觉呼吸一窒！" NOR;

 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);

 msg =  HIW "$N刀光连闪，$n周围鬼哭神号，恰似无边地狱！\n" NOR;

        message_vision(msg, me, target);

lvl=extra/10;

  if(lvl>4) lvl =2;

for(i=0;i<=lvl;i++)

 {

 msg = HIY "$N劈出一刀！\n" NOR;

 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);

 message_vision(msg,me,target);

 }

 me->add_temp("apply/att

ack", -extra);

// me->add_temp("apply/damage", -extra);

  me->start_busy(1+lvl/2);

 return 1;

}

