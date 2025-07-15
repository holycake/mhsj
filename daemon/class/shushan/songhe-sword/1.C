#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,k,damage;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内功太差。\n");


        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("xianfeng-spells", 1) < 100)
                return notify_fail("你的仙风云体术等级不够，不能使用这一招！\n");
        k=(int)me->query_skill("sword");
       j=(int)target->query_skill("dodge");
       if(k<150)
                return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
        
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIB"\n$N仰天大喝了一声："NOR,me,target);
message_vision(HIW"\n助我克敌者赏雌剑一柄！"NOR,me,target);
message_vision(HIB"\n一刹那间千万剑光破空而来，劈面罩向$n"NOR,me,target);
for (i=0;i<=k;i++)
           {
if (random(k*10+j)>j) {
           message_vision(HIY"\n$n一个不慎，中了一剑"NOR,me,target);
            damage=15+random(15);

        target->receive_damage("kee",damage);
            COMBAT_D->report_status(target);
        me->receive_damage("sen", 1);
        me->add("force", -5);
              me->add("kee", -5);
           }
             else {
           message_vision(HIY"\n$n左跳右闪，好不容易避开了一轮剑雨"NOR,me,target);
             }
             }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }     
    me->start_busy(5);
        return 1;
}