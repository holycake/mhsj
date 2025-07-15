#include <ansi.h>
inherit SSERVER;

int perform(object me,object target)
{
  string msg;
object weapon;
  int lvl,power;
  if (!target) target=offensive_target(me);
  if (environment(me)->query("no_fight")==1)
    return notify_fail("此处不许战斗.\n");
  if (!target||!target->is_character()||!me->is_fighting(target))
    return notify_fail("[一剑落九雁]只能对战斗对手使用.\n");
  if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
            return notify_fail("你应该用剑才能使出这招。\n");
  lvl=me->query_skill("snowsword",1);
  lvl=(int)(lvl/20);
  if (lvl<1) return notify_fail("你的风回雪舞剑法修炼不足.\n");
  if (lvl>9) lvl=9;
    if (me->query("force")<50*lvl)
    return notify_fail("你内力不足,无法使出这招.\n");
  msg=RED+"$N使出[一剑落"+chinese_number(lvl)+"雁],幻出数道剑影向$n攻去.\n"+NOR;
    me->start_busy(3);
  if (random(me->query("combat_exp"))>random(target->query("combat_exp")/2))
 {
   power=(int)me->query_str()*lvl-target->query_str();
   if (power<0) power=10;
  msg+=RED+"$n躲闪不及,身上划出几道大口子.流血不止.\n"+NOR;
  target->receive_wound("kee",power);
  target->receive_damage("kee",power/2);
    me->add("force",-50*lvl);
 }
 else 
   msg+=CYN+"$n身形一展,轻轻巧巧躲过了这招.\n"+NOR;
 message_vision(msg, me, target);
 return 1;
 }
