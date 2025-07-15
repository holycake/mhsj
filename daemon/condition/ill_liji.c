// ill_liji.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "的脸上五官挪位，捂着肚子到处找厕所，看来象是得了痢疾了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你的肚子难受极了，直想上厕所。\n" NOR );
      message("vision", me->name() + "捂着肚子到处找厕所，看来是得了痢疾了。\n",
            environment(me), me);
   }
   me->receive_wound("kee", 2);
   me->receive_damage("kee", 2);
   me->apply_condition("ill_liji", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
