inherit SKILL;
mapping *action = ({
	([	"name":			"飞花落燕",
		"action":
"$N手中$w大开大阖，每一剑向$n劈去，都有似开山大斧一般，好一招势道雄的「飞花落燕」",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"劈伤"
	]),
	([	"name":			"雪花飞天",
		"action":
"只见$N身形稍退，右足点地斜斜跃起，手中$w笔直地向$n的$l刺去\n"
"正是一招「雪花飞天」！",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
        ([      "name":                 "落花飞雪",
                "action":
"$N飞身上前，手中$w疾舞，一招「落花飞雪」幻出团团剑芒，将$n紧紧裹在其中",
		"dodge":		-10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "剑花追魂",
                "action":
"$N打到兴发，蓦地里一声清啸，手中$w冲天而起，直指$n的$l！这招山崩海啸般的「剑花追魂」完全将$n惊呆了",
                "dodge":                -10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "花落四方",
                "action":
"只见$N单足点地，使出一招「花落四方」，手中$w疾进，幻出点点寒星，直刺$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "太白飞花",
                "action":
"$N蓦然跃起，一式「太白飞花」，身随剑起，向$n背心疾刺数剑，招招势若暴风骤雨，$n哪里闪避得过",
		"dodge":		-5,
		"parry":		-5,
		"damage":		20,
		"damage_type":		"刺伤"
	]),
	([	"name":			"落影神花",
		"action":
"$N左手捏着剑决，右手剑不住抖动，一式「落影神花」，手中$w平平刺出，\n"
"剑尖急颤，根本不知攻向何处",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"花飘万家",
		"action":
"$N吸一口气，手中连环七剑，一剑快似一剑，一式「花飘万家」，剑法轻灵飘逸，如风如雨般的攻向$n的$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
});
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力修为不够深，无法学习飞花剑法。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("feihua-sword");
	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练飞花剑法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练飞花剑法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍飞花剑法。\n", me);
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
        return CLASS_D("yhg") + "/feihua-sword/"+func;
}
