//ji.c by yushu 2000.9
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,damage;
        weapon = me->query_temp("weapon");
        
              if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「祭枪」？\n");
//			  	if(me->query("family/family_name")!="火云洞")
// return notify_fail("“祭枪”只有火云洞门人才可以用！\n");

        if(!me->is_fighting())
                return notify_fail("「祭枪」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不足！\n");
               
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
              
        if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("祭枪必须配合火魔心法才能使用。\n");
          


   i=(int)me->query_skill("huoyun-qiang",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("你的火云枪级别还不够，使用这一招会有困难！\n");

   message_vision(HIR"\n只见$N向"+weapon->query("name")+HIR"上吐了口鲜血,大喝一声:祭枪！\n"NOR,me);

   me->delete("env/brief_message");
   target->delete("env/brief_message");

   me->set_temp("HYQ_perform", 1);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->delete_temp("HYQ_perform");

   me->receive_damage("sen", 30+random(100));
   me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(0);
        return 1;
}

