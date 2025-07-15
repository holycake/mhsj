// taiji-jian.c 太极剑

inherit SKILL;

mapping *action = ({
([	"action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 25,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「太极无门」直刺$n的$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 30,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 170,
	"dodge" : 15,
	"damage" : 40,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「八方神剑」，$w划出八道剑光，剑锋直出，绵绵不断划向$n的$l",
	"force" : 240,
	"dodge" : 10,
	"damage" : 60,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招「御剑降魔」，右手$w带着一团剑花，逼向$n的$l",
	"force" : 280,
	"dodge" : 5,
	"damage" : 70,
	"damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「剑身出窍」，$w中宫直进，刺向$n的$l",
	"force" : 380,
	"dodge" : -5,
	"damage" : 115,
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力修为不够深，无法学习太极剑法。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("taiji-jian");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练太极剑法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练太极剑法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍太极剑法。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("wudang") + "/taiji-jian/"+func;
}
