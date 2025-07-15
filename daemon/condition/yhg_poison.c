// yhg_poison.c
#include <ansi.h>
int update_condition(object me, int duration)
{
	me->receive_wound("sen", duration);
	me->receive_damage("sen", duration);
	me->receive_damage("kee", duration);
	me->receive_wound("kee", duration);
	me->set_temp("death_msg","精力耗尽而死。\n");
	me->apply_condition("yhg_poison", duration);
	if (duration >0 )
	tell_object(me, HIG "忽然从你的口中吐出一滩黑血，你感觉有点支持不住了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
