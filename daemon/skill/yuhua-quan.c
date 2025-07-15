inherit SKILL;

mapping *action = ({
	([	"action":		"$N浅浅一笑，一招「花拳无影」若有若无地拍向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		-5,
		"force":		50,
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N身形一顿，似有退意。$n正待反攻，\n忽见$N纤纤五指，直拂$n双目。正是“玉花拳”之杀手「借花谢佛」",
		"dodge":		-10,
		"force":		-5,
		"parry":		-10,
		"force":		120,
		"damage_type":	"刺伤",
                        "weapon":		"右手掌",
	]),
	([	"action":		"只见$N嫣然一笑，双掌翻飞，一招「拳花上身」当真是妙到毫巅",
		"dodge":		-20,
		"force":		-5,
		"parry":		-20,
		"force":		70,
		"damage_type":	"瘀伤",
	]),
	([	"action":		"只见$N嫣然一笑，双掌翻飞，一招「飞花御拳」当真是妙到毫巅",
		"dodge":		-20,
		"force":		-5,
		"parry":		-20,
		"force":		70,
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N纤腰一摆，陡然滑出数尺，右手顺势一招「扑花捉影」往$n的$l拍去",
		"dodge":		15,
		"force":		-5,
		"parry":		15,
		"force":		60,
		"damage_type":	"瘀伤",
	]),
            ([	"action":		"只见$N双唇紧闭，面色凝重，一招「双全采花」全力击向$n的$l",
		"dodge":		5,
		"force":		-5,
		"parry":		5,
		"force":		80,
		"damage_type":	"瘀伤",
	]),
});

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("玉花拳是只有女子才能练的武功。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练玉花掌必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed"|| (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("yhg") + "/yuhua-quan/" + func;
}
