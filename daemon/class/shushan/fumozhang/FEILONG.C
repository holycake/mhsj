// feilong.c by yushu@SHXY 2000.11
#include <ansi.h>
int perform(object me)
{
      string msg;
      object weapon, weapon2, target;
      int skill, dp, damage;

      me->clean_up_enemy();
      target = me->select_opponent();

      if( (int)me->query_temp("feilong") )
              return notify_fail("你已经够忙得了。\n");
      skill = me->query_skill("fumozhang",1);
      if( !(me->is_fighting() ))
              return notify_fail("飞龙探云手只能对战斗中的对手使用。\n");

      if (objectp(weapon = me->query_temp("weapon")))
              return notify_fail("你必须空手。\n");

      if (!objectp(weapon2 = target->query_temp("weapon")))
         return notify_fail("对方没有兵刃，你不用担心。\n");

      if( skill < 50)
              return notify_fail("你的伏魔掌等级不够, 不使用飞龙探云手！\n");

      if( me->query("force") < 50 )
              return notify_fail("你的内力不够，无法飞龙探云手！\n");
      msg = CYN "$N凝神闭息，打算施展飞龙探云手夺取对方兵器. \n";
      message_vision(msg, me);

      dp = target->query("str") * 3;
      if( dp < 1 )
              dp = 1;
      if( random(skill) > dp )
      {
              if(userp(me))
                      me->add("force",-50);
              msg = HIW"$N使出飞龙探云手的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
              target->start_busy(2);
              weapon2->move(me);
              me->start_busy(random(1));
      }
      else
      {
              msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
              me->start_busy(random(3));
      }
      message_vision(msg, me, target);

      return 1;
}
