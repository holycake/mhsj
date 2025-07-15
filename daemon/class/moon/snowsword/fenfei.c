#include <ansi.h>
#include <combat.h>
inherit SSERVER;
nosave object *enemy = ({});
int perform(object me, object target)
{
        int extra;
        int rir;
        mapping map;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("snowsword",1);
        if ( extra < 60) return notify_fail("你的风回雪舞剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIW"雪花纷飞"+HIR+"只能对战斗中的对手使用。\n"NOR);
        if (me->query("force")<=1000) return notify_fail("你的内力不足，无法使用"+HIW"雪花纷飞"NOR+"\n");
        map = me->query_skill_map();
        if( undefinedp(map["sword"]) ) 
                return notify_fail("你没有使用剑法\n");
          if( map["sword"] != "snowsword" )
                 return notify_fail("你并没有使用剑法\n");
        weapon = me->query_temp("weapon");      
        if( !objectp(weapon) || weapon->query("skill_type")!= "sword" )
                return notify_fail("你并没有使用剑法\n");
        rir = target->query_skill("dodge",1);
        me->add("force",-200);
        me->add("sen",-50);
        message_vision("$N使出月宫之不传之秘「"+HIB"雪花纷飞"NOR+"」\n",me);
//        me->start_busy(1);
        if (random(me->query("combat_exp")*(extra/1+1))>target->query("combat_exp")*(rir/1+1))
        {
          weapon = me->query_temp("weapon");
            message_vision(HIM "$N忽然将手中的"+weapon->query("name")+HIM"抛向天空中，"+weapon->query("name")+HIM"有如雪花般在天空飞舞。\n" NOR,me,target);
         if ( extra > 200)
               {
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          message_vision(HIC "$N闪电般攻出了五招,$n被剑气攻击的手忙脚乱！\n" NOR,me,target);
               }  
             else if ( extra > 150)
              {
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          message_vision(HIC "$N闪电般攻出了四招,$n被剑气攻击的手忙脚乱！\n" NOR,me,target);
              } else if ( extra > 100)
             {
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          message_vision(HIC "$N闪电般攻出了三招,$n被剑气攻击的手忙脚乱！\n" NOR,me,target);
             } else
             {
          COMBAT_D->do_attack(me,target, weapon);  
          COMBAT_D->do_attack(me,target, weapon);  
          message_vision(HIC "$N闪电般攻出了两招，$n被剑气攻击的手忙脚乱！\n" NOR,me,target);
             }
          target->receive_damage("kee",0,me);
          target->start_busy(1);
        }
        else
        {
          message_vision("但$n看破$N的招式，趁势发动攻击！\n",me,target);
          weapon = target->query_temp("weapon");
          COMBAT_D->do_attack(target,me,weapon);
        }
        return 1;
}
