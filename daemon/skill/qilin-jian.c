//【麒麟剑法】qilin.c

/*
麒麟剑法    dodge  10    parry  10    damage  50
*/

//麒麟初现，一剑封喉，麒麟出窍，万剑穿心
//麒麟绝影，九麒归一，麒麟之火，圣物麒麟，无敌麒麟

inherit SKILL;


mapping *action = ({
	([	"name":			"麒麟初现",
		"action":
"$N手中$w大开大阖，每一剑向$n劈去，都有似开山大斧一般，好一招势道雄的「麒麟初现」",
		"dodge":		10,
		"parry":		10,
		"damage":		100,
		"damage_type":		"劈伤"
	]),
	([	"name":			"一剑封喉",
		"action":
"只见$N身形稍退，右足点地斜斜跃起，手中$w笔直地向$n的$l刺去\n"
"正是一招「一剑封喉」！",
		"dodge":		10,
		"parry":		10,
		"damage":		100,
		"damage_type":		"刺伤"
	]),
        ([      "name":                 "麒麟出窍",
                "action":
"$N飞身上前，手中$w疾舞，一招「麒麟出窍」幻出团团剑芒，将$n紧紧裹在其中",
		"dodge":		10,
                "parry":                10,
                "damage":               100,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "万剑穿心",
                "action":
"$N打到兴发，蓦地里一声清啸，手中$w冲天而起，直指$n的$l！这招山崩海啸般的「万剑穿心」完全将$n惊呆了",
                "dodge":                10,
                "parry":                10,
                "damage":               100,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "麒麟绝影",
                "action":
"只见$N单足点地，使出一招「麒麟绝影」，手中$w疾进，幻出点点寒星，直刺$n的$l",
                "dodge":                10,
                "parry":                10,
                "damage":               100,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "九麒归一",
                "action":
"$N蓦然跃起，一式「九麒归一」，身随剑起，向$n背心疾刺数剑，招招势若暴风骤雨，$n哪里闪避得过",
		"dodge":		10,
		"parry":		10,
		"damage":		100,
		"damage_type":		"刺伤"
	]),
	([	"name":			"麒麟之火",
		"action":
"$N左手捏着剑决，右手剑不住抖动，一式「麒麟之火」，手中$w平平刺出，\n"
"剑尖急颤，根本不知攻向何处",
		"dodge":		10,
		"parry":		10,
		"damage":		100,
		"damage_type":		"劈伤"
	]),
	([	"name":			"圣物麒麟",
		"action":
"$N吸一口气，手中连环七剑，一剑快似一剑，一式「圣物麒麟」，剑法轻灵飘逸，如风如雨般的攻向$n的$l",
		"dodge":		10,
		"parry":		10,
		"damage":		100,
		"damage_type":		"刺伤"
	]),
       ([      "name":                 "无敌麒麟",
                "action":
"只见$N挽出十数朵剑花，化作十数道五彩剑虹将$n罩在其中，$n哪里识得这招「无敌麒麟」的利害",
                "dodge":                25,
                "parry":                25,
                "damage":               250,
                "damage_type":          "劈伤"
       ]),

});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，无法学习百鸟剑法。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("qilin-jian");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练麒麟剑法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练麒麟剑法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍麒麟剑法。\n", me);
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
        return CLASS_D("yaomo") + "/wiz/qilin-jian/"+func;
}
