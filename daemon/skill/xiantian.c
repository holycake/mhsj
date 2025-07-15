// xiantian-force 【先天乾坤功】

/*
先天乾坤功
引动九天之外灵气集于一身为己用，当练到第九重的时候，可以引动天地灵
气，使用一招“倒转天地”把天地乾坤都倒转，在场所有人无一幸免。
*/

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("先天乾坤功只能向师父学，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("wusheng") + "/xiantian/" + func;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else if ( level < 290 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 3 )
		return BLU "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 5 )
		return HIB "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 7 )
		return YEL "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 9 )
		return CYN "第"+chinese_number( stage(level) )+"重　" NOR;
	else 
		return HIW "第"+chinese_number( stage(level) )+"重　" NOR;
}