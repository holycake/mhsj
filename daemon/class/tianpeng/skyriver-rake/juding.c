//juding.c 
// by mhsj@gslxz 2001/7/25

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        int ii,req,num_pahen,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string pahen_type,b_unit;

   int wound=0;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你要攻击谁？\n");
       
        if(!me->is_fighting())
                return notify_fail(HIR"「三花聚顶」"NOR+WHT"只能在战斗中使用！\n"NOR);
 
      weapon = me->query_temp("weapon");
      req=(int)me->query_skill("rake", 1)+(int)me->query_skill("skyriver-rake", 1); 

       if(me->query("family/family_name") != "天蓬府")
                return notify_fail("[三花聚顶]只有天蓬府弟子才能使用！\n");

      if (weapon)  

      if (me->query_skill_mapped("force")!="tianpeng-force")
                return notify_fail("[三花聚顶]必须配合天蓬心法才能使用。\n");
      if(req < 80)
            return notify_fail(WHT"以你的级别，还不能够使用"HIR"[三花聚顶]"NOR+WHT"！\n");
       if (me->query("force")<200)
           return notify_fail(WHT"你内力不继，不能使用"HIR"[三花聚顶]"NOR+WHT"。\n");

        if( time()-(int)me->query_temp("juding_end") < 3 )
                return notify_fail("此招不能使用太多！\n");

         me->add("force", -100);

        if(num_pahen <=0) 
           { pahen_type="钯痕"; damage=me->query("force_factor")+100; }
        else if (req < 150)
           { pahen_type=weapon->query("pahen/type"); damage=me->query_temp("apply/damage");}

        msg = HIY"$N挥舞着手中"NOR+weapon->query("name")+HIY"对$n"HIY"使出了一朝天蓬府绝技"HIR"[三花聚顶]"HIY"！\n" NOR;

        if (num_pahen > 100 || num_pahen == 0) max_hit=100;
        else max_hit=weapon->query("pahen/now");

        num_hit=random(max_hit/2)+(max_hit/2);

        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;

        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp")/135;
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}

        if (hitt==0)
	  {
           msg += HIY "$n"HIY"连忙运功护体，夺过了$N的一击。\n"NOR;
           message_vision(msg, me, target);
//           me->start_busy(random(3));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
    if (random(damage)>target->query_temp("apply/armor"))  {
       target->receive_wound("kee",damage-target->query_temp("apply/armor"),me);
       wound=1;
  }
           msg += HIY "$N向着$n"HIY"就是"+chinese_number(hitt)+HIY"钯，$n"HIY"躲闪不及，身上被$N手中的\n"NOR+weapon->query("name")+HIY"打个正着。！\n"NOR;
           message_vision(msg, me, target);
       me->start_busy(random(2));
     COMBAT_D->report_status(target,wound);
           if(!target->is_busy())
           target->start_busy(random(5));
           }
        msg = HIY "$n"HIY"后退了几步对着$N高声叫道：敢在太岁爷头上动土，我看你活\n的不耐烦了！\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);
    me->set_temp("juding_end",time());
    call_out("remove_effect",3+random(5),me);
        return 1;
}

