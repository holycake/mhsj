// zhang.c by greenwc
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void sword_ok(object);
int perform(object me, object target)
{
int ap,dp,damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「双掌伏魔」？\n");
        if(!me->is_fighting())
                return notify_fail("「双掌伏魔」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不足！\n");
          if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query_skill("sword") < 100)
                return notify_fail("你的剑法不够熟练，使用这一招会有困难！\n");
        if((int)me->query_skill("force") < 100)
                return notify_fail("你的内功底子不好，很难用出双掌伏魔！\n");
        if((int)me->query_skill("unarmed") < 100)
                return notify_fail("你的掌法不够熟练，使用这一招会有困难！\n");
          if(me->query_temp("no_sword"))
                        return notify_fail("你刚刚发过双掌伏魔，不要再妄动真气了！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIC"\n$N一声大喝，双掌忽然放出紫青寒光，直略$n！\n"NOR,me,target);
ap=(int)me->query("combat_exp");
dp=(int)target->query("combat_exp");
damage=random((int)me->query_skill("unarmed"))+random((int)me->query_skill("force"))+random((int)me->query_skill("sword"));
if (random(ap)>dp/2)
{
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else {
message_vision(HIW"\n$n吸胸收腹，勉强避开了这一击！\n"NOR,me,target);
}
me->add("force", -100);
        me->set_temp("no_sword",1);
                call_out("sword_ok",1+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}
void sword_ok(object me)
{
if (!me) return;
      me->delete_temp("no_sword");
}
