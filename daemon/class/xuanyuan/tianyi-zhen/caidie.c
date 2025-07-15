
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        object ob;
        string msg;
        int extra;
         if( !target ) target = offensive_target(me);
         if( !target
          || !me->is_fighting()
        || !me->is_fighting(target)  )
                return notify_fail("「彩碟纷飞」只能在战斗中使用。\n");

       if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "unarmed" )
                return notify_fail("使用「彩碟纷飞」必须拿根针！\n"); 

        if( (int)me->query("force") < 250 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("tianyi-zhen",1) < 60 )
                return notify_fail("你的天一针法等级不够.\n");


        msg = HIY "$N使出轩辕古墓的绝技「彩碟纷飞」，身法顿时变的十分轻盈！\n" NOR;

        message_vision(msg, me);

        extra=me->query_skill("tianyi-zhen",1)*3/4;

        me->add_temp("apply/attack",extra);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       
        me->add_temp("apply/attack",-extra);
        
        me->add("force", -100);
        me->start_busy(2);

        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}
