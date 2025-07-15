// ice_poison.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage_kee=10, damage_sen=10;

	if(me->query("max_kee")>200)
		damage_kee=me->query("max_kee")/30;
	if(me->query("max_sen")>200)
		damage_sen=me->query("max_sen")/30;
        if(damage_kee > 5) damage_kee = 5;
        if(damage_sen > 5) damage_sen = 5;
                                                	
	me->receive_wound("sen", damage_sen);
	me->receive_wound("kee", damage_kee);
	me->set_temp("death_msg","被冰刀的寒意冻死了。\n");
	me->apply_condition("bp_poison", duration - 1);

	if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
		message_vision("$N嘴唇乌青发亮，浑身抖个不停，不知道中了什么邪。\n", me);
	else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
		message_vision("$N嘴唇发青，身子微微发抖，好象冷得厉害。\n", me);		
	else 
		message_vision("$N打了个寒颤。\n", me);
		
	if( duration < 1 ) return 0;
	return 1;
}


