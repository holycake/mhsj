// drift_sense.c

#include <ansi.h>

inherit F_CLEAN_UP;

int cast(object me)

{

 object target = find_living("ghost");

 if(!target) return notify_fail("你要找的鬼没有发现?\n");

 if( me->is_fighting() )

  return notify_fail("战斗中无法使用寻鬼术！\n");

 if( me->query("mana") < 30 )

  return notify_fail("你的法力不够！\n");

        if( me->query("sen") <= 35 )

                return notify_fail("你的体力不够！\n");

 if( !target->is_ghost())

  return notify_fail("寻鬼术只能找鬼！\n");

        if((int) me->query_skill("gouhunshu",1) < 10)

                return notify_fail("你的勾魂术不够高深！");

 me->add("mana", -30);

 me->receive_damage("sen", 30);

 message_vision( HIY "$N低头闭目，开始施展寻鬼术 ....\n" NOR, me);

//        if( random(50) >

 //(int)(me->query_skill("gouhunshu"))){

  //              write("你因为不够熟练而失败了。\n");

   //             return;

    //    }

 message_vision( HIY"\n一团黑气忽然罩住$N，几秒钟後，黑气和人一齐消失得无影无踪！\n\n" NOR,me);

 me->move(environment(target));

 message_vision(HIY"\n你的眼前突然出现一团黑气，黑气中露出一个人影！\n\n" NOR,me);

 return 1;

}

