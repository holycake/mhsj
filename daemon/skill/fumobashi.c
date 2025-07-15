//fumobashi 【伏魔八式】

/*
伏魔八式    dodge  +10    parry  +10    damage  65
共八式，当年少林祖师“达魔祖师”所创。分前后四式，前四式导人顿悟，引
魔惨悔；后四式降龙伏虎，超导众生。当年达魔曾空手用此伏魔八式降魔除
妖，为普渡众生出力不少。其中的第九式乃集八式威力于一身，以全身内力
引动发出，可真惊天地，泣鬼神！！！
*/

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":		"$N一招"HIW"「尊者引路」"NOR"，左手抓向$n的丹田，就在$n回身自防的一瞬间，右手却已掐上了$n的$l",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"刺伤",
                        "weapon":		"右手食指",
	]),
	([	"action": "$N双手一翻，出"HIB"「群妖伏首」"NOR"，双手如穿花蝴蝶一般上下翻飞。\n$n看花了眼，刹那间$N已欺身到了眼前",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"内伤",
                        "weapon":		"右手",
	]),
	([	"action":		"只见$N一转身，一指由胁下穿出，疾刺$n的$l，却正是一招"HIY"「天降梵音」"NOR,
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"刺伤",
                        "weapon":		"左手食指",
	]),
	([	"action":		"$N双掌一错，掌心向外横推而出，这一招"HIG"「大彻大悟」"NOR"带着一股罡风扑向$n的$l",
		"dodge":		20,
		"parry":		20,
		"force":		140,
		"damage_type":	"内伤",
                        "weapon":		"左手", 
	]),
        ([	"action":		"$N一招"HIC"「惊天动地」"NOR"，左手在空中虚划了个半弧，拍向$n的$l",
		"dodge":		30,
		"parry":		10,
		"force":		70,
		"damage_type":	"内伤",
                        "weapon":		"左手",
	]),
        ([	"action":		"忽听$N一声怒吼，右手高高举起，一式"RED"「打入轮回」"NOR"，砍向$n的$l",
		"dodge":		10,
		"parry":		-10,
		"force":		220,
		"damage_type":	"砍伤",
                        "weapon":		"右手",
	]),
	([	"action":		"只见$N一转身，一式"HIM"「佛动山河」"NOR"由胁下穿出，疾刺$n的$l",
		"dodge":		-15,
		"parry":		10,
		"force":		300,
		"damage_type":	"砍伤",
                        "weapon":		"左手",
        ]),
        ([	"action":		"只见$N面带微笑，负手而立，使出一式"HIR"「雷动九山」"NOR"。但是$n觉得有一道指力直扑$l而来",
		"dodge":		15,
		"parry":		-5,
		"force":		320,
		"damage_type":	"内伤",
                        "weapon":		"右手",
        ]),
	([  "action": 	HIR"$N双掌一错，左右手突发青红之光，随着一声霹雳，青红两色火球电般地射向了$n"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                500,
                "damage_type":  "内伤",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("伏魔八式必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("fumobashi_per");
        if( !me->query_temp("fumobashi_per") ) {
        return action[random(8)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习伏魔八式。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍伏魔八式。\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("wusheng") + "/fumobashi/" + func;
}

