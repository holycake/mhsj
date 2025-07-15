#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
int def;
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target||!target->is_character()||!me->is_fighting(target) )
            return notify_fail("你只能对战斗中的对手使用「玄狐再现」。\n");
    
    if( (int)me->query_skill("xuanhu-blade",1) < 40)
            return notify_fail("你目前功力还使不出「玄狐再现」。\n");
  
    if( (int)me->query("force") < 200 )
            return notify_fail("你的内力不够。\n");
   
        if(! me->query_temp("weapon") )
                return notify_fail("你必须用兵器才能使用绝技！\n");
    me->add("force", -100);
    msg = HIC"$N对着$n嫣然一笑，顿时六宫粉黛皆无颜，说时迟，那时快！"+
    "$N手中的刀弯成了狐型，刹那间已连劈出三刀，$n的脸顿时如纸样煞白。\n"NOR;
    me->start_busy(2);

    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/3 ) {

   // target->start_busy( (int)me->query_skill("xuanhu-blade") / 20 );
    damage = (int)me->query_skill("xuanhu-blade", 1)+(int)me->query_skill("blade", 1);
    damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
  damage -=damage*def/3000;
    target->receive_damage("kee", damage,me);
    target->receive_wound("kee", damage/2,me);
   msg += RED
"只见$n已被$N切得体无完肤，血如箭般由全身喷射而出！\n"NOR;
   target->start_busy(1+ random(1+(int)me->query_skill("xuanhu-blade") / 150) );
   me->start_busy(2+random(1+(int)target->query_skill("force") / 150));
    } else {
    msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
}
