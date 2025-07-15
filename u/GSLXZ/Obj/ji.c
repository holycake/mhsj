#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;
    int skill;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
        return notify_fail(RED"装备枪才能使用「祭枪」？\n"NOR);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail(HIW"你只能在战斗中使用。\n"NOR);

    if ((int)me->query_skill("huoyun-qiang", 1) < 60 )
        return notify_fail(WHT"你火云枪法不够娴熟，使不出「祭枪」。\n"NOR);

      if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail(HIC"这一招式必须配合火魔心法才能使用。\n"HIC);
if(me->is_busy())
return notify_fail("你现在正忙着！！\n");

      if (me->query_skill_mapped("spells")!="pingtian-dafa")
                return notify_fail(HIC"这一招式必须配合平天大法才能使用。\n"NOR);

    if ((int)me->query_skill("huomoforce", 1) < 60 )
        return notify_fail(RED"你的火魔心法火候不够，使不出「祭枪」。\n"NOR);
    if ((int)me->query("max_force") < 600)
        return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
    if ((int)me->query("force") < 600)
    {
        return notify_fail(HIC"你现在内力不足，不能继续使用「祭枪」！\n"NOR);
    }
       skill = me->query_skill("huoyun-qiang",1);

message_vision(RED"\n$N猛然大喝一声: "BLINK+HIR"「祭枪」 \n"NOR,me,target);

    msg = RED "$N右手持枪,枪尖向左肩一划，一阵血珠溅满枪头，紧接着枪随右臂刺出，一片血光
裹住漫天血光枪影向"+NOR"$n"+RED"狂风般呼啸刺去，\n"NOR;

   if((int)me->query_int()  > (int)target->query_int()/3 +random(5) ) {
damage=me->query_skill("huomoforce")/2 + me->query_skill("spear")/2 + me->
query_skill("huoyun-qiang")/2 + me->query("max_force")/2;
//           damage = skill - ((int)target->query("max_force")/50);
           if( damage > 0 ) {
msg += "$n"+CYN"疾忙侧身避让，但血枪之光疾闪，只觉眼前一阵血红，枪尖劈面而下，鲜血飞溅，惨声大嚎！\n"NOR;
          me->add("force", -250); //使用一次减掉内力前值250点 
          me->start_busy(random(5));//随即产生5秒以内的busy
          target->receive_wound("kee", damage/4);//对于气血的伤害 :P
     }
        }
else
msg += WHT"可是"+NOR"$n"+WHT"侧身避让，不慌不忙，躲过了$N的血枪。\n"NOR;
        me->start_busy(1);//被打中的目标也有1个busy  
  
      message_vision(msg, me, target);
        target->kill_ob(me);

        return 1;
}

 
 

  
