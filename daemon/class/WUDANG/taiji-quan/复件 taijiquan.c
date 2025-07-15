#include <ansi.h>
int perform(object me)
{
      string msg;
      object weapon, target;
      int skill,skill1, dp, damage;
      me->clean_up_enemy();
      target = me->select_opponent();
      if( (int)me->query_temp("taiji-quan")/6)
              return notify_fail("你已经够忙得了。\n");
      skill = me->query_skill("taiji-quan",1);
      skill1 = me->query_skill("unarmed",1);
       if( !(me->is_fighting() ))
              return notify_fail("太极拳只能对战斗中的对手使用。\n");
      if (me->query_skill_mapped("force")!="wudang-force")
                return notify_fail("太极拳必须配合武当心法才能使用。\n");if (objectp(weapon = me->query_temp("weapon")))
              return notify_fail("你必须空手。\n");
      if( skill < 40)
              return notify_fail("你的太极拳等级不够, 不使用太极拳！\n");
      if( skill1 < 40)
              return notify_fail("你的基本拳法等级不够, 不使用太极拳！\n");
      if( me->query("force") <600 )
              return notify_fail("你的内力不够，无法使用太极拳！\n");
      msg = CYN "$N凝神闭息，打算施展太极八卦拳。 \n";
      message_vision(msg, me);
      dp = target->query("str") * 3;
      if( dp < 1 )
              dp = 1;
      if( random(skill) > dp )
      {
              if(userp(me))
                      me->add("force",-120);
              msg = HIW"$N使出太极拳的绝招, $n顿时觉得眼前一花，身体一软，被$N打的鼻青眼肿！\n" NOR;
	me->delete("env/brief_message");
	target->delete("env/brief_message");
        me->set_temp("QJB_perform", 1/160);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              target->start_busy(2);
      }
      else
      {
              msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能有施展太极拳的时机。\n"NOR;
              me->start_busy(0);
      }
      message_vision(msg, me, target);
      return 1;
}
