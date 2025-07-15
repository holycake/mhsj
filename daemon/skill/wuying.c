// wuying-sword 【无影剑】

/*
无影剑    dodge  -10    parry  -10    damage  65
此剑法为剑魔独孤求败中年时所创，剑魔中年时已经练得无剑胜有剑的境界，
出剑快如电闪、猛如雷鸣、狂如风卷、轻如云动，独此名为“无影剑”。间有
四招！分别为电、雷、风、云。
*/

inherit SKILL;

mapping *action = ({
	([	"name":			"云",
		"action":
"$N一抖手中的$w，瞬间刺出三十六剑，$n顿时手忙脚乱，分不清虚实",
		"dodge":		-10,
                "parry":                -10,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "风",
		"action":
"$N一剑刺向$n，$n急忙向旁边一闪，\n"
"不料$N一运劲儿，手中的$w突然弯了过来，转而刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		45,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "雷",
		"action":
"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，$N左手剑指已刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		55,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "电",
		"action":
"$N一转身，背向$n，手中$w从腋下反手刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		65,
		"damage_type":		"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练无影剑。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习无影剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍无影剑。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
	return CLASS_D("wusheng") + "/wuying/"+func;
}