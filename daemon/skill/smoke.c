inherit SKILL;

#include <ansi.h>

string level_description(int level)
{
	if ( level < 10 )
		return BLU "初犯烟瘾" NOR;
	else if ( level < 20 )
		return HIB "见烟冒烟" NOR;
	else if ( level < 30 )
		return YEL "嗜烟如命" NOR;
	else if ( level < 40 )
		return CYN "烟气冲天" NOR;
	else if ( level< 50 )
		return HIW "肺如黑炭" NOR;
	else 
		return HIR "无可救药" NOR;
}

