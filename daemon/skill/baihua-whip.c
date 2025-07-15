inherit SKILL;
mapping *action =
({
([
"action" : "只见$N纤腰急转，皓腕轻抖，一式「百花追魂」，$w在身畔化作百道飞虹",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"lvl"         : 0,
"skill_name"  : "百花追魂",
"damage_type" : "割伤",
]),
([
"action" : 
"$N默运冰心决，使出「一叶丛林」，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"lvl"         : 10,
"skill_name"  : "一叶丛林",
"damage_type" : "内伤",
]),
([
"action" : 
"$N一式「鞭魂如影」，神色凄楚惘然，$w斜斜舞出，$n心中一凛，只觉得这目光似曾相识，却又说不上来",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"lvl"         : 20,
"skill_name"  : "鞭魂如影",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N霞袖慢垂，莲步急趋，手中$w似影随形，一招「百花齐放」愈显落落欲往，矫矫不群",
"dodge"  : -10,
"damage" : 30,
"parry"  : -10,
"lvl"         : 30,
"skill_name"  : "百花齐放",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N徐徐舞动$w，却是一招「落燕飞鞭」，只见招断意连，缠绵婉转，一鞭未绝，便隐隐有万鞭相随",
"dodge"  : 0,
"damage" : 20,
"parry"  : 0,
"lvl"         : 40,
"skill_name"  : "落燕飞鞭",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「飞影丛花」，$w挥洒自如，霎时间绛雪纷纷，娇如柳絮，弱似梨花，密密裹住$n全身"
,
"dodge"  : -10,
"damage" : 25,
"parry"  : -10,
"lvl"         : 50,
"skill_name"  : "飞影丛花",
"damage_type" : "刺伤",
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("你的内力不够，没有办法练百花鞭法, 多练些内力再来吧。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练百花鞭法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 10 )
		return notify_fail("你的内力或气不够，没有办法练习百花鞭法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	write("你按著所学练了一遍百花鞭法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
	return CLASS_D("yhg") + "/baihua-whip/"+func;
}
