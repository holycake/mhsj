// sgzl
// 百鸟剑法，

/*
百鸟剑法    dodge  -5    parry  -5    damage  20
雪山派高手模仿百禽搏斗的动作而得
*/

// 大鹏展翅,鹰击长空,凤舞九天,雄鸡报晓,鹗立云端,鸿飞天外
// 杜鹃啼血,燕语报春,鹤影寒塘,孔雀开屏,鹦鹉学舌,鸳鸯戏水

inherit SKILL;


mapping *action = ({
	([	"name":			"大鹏展翅",
		"action":
"$N手中$w大开大阖，每一剑向$n劈去，都有似开山大斧一般，好一招势道雄的「大鹏展翅」",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"劈伤"
	]),
	([	"name":			"鹰击长空",
		"action":
"只见$N身形稍退，右足点地斜斜跃起，手中$w笔直地向$n的$l刺去\n"
"正是一招「鹰击长空」！",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
        ([      "name":                 "凤舞九天",
                "action":
"$N飞身上前，手中$w疾舞，一招「凤舞九天」幻出团团剑芒，将$n紧紧裹在其中",
		"dodge":		-10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "雄鸡报晓",
                "action":
"$N打到兴发，蓦地里一声清啸，手中$w冲天而起，直指$n的$l！这招山崩海啸版的「雄鸡报晓」完全将$n惊呆了",
                "dodge":                -10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "鹗立云端",
                "action":
"只见$N单足点地，使出一招「鹗立云端」，手中$w疾进，幻出点点寒星，直刺$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "鸿飞天外",
                "action":
"$N蓦然跃起，一式「鸿飞天外」，身随剑起，向$n背心疾刺数剑，招招势若暴风骤雨，$n哪里闪避得过",
		"dodge":		-5,
		"parry":		-5,
		"damage":		20,
		"damage_type":		"刺伤"
	]),
	([	"name":			"杜鹃啼血",
		"action":
"$N左手捏着剑决，右手剑不住抖动，一式「杜鹃啼血」，手中$w平平刺出，\n"
"剑尖急颤，根本不知攻向何处",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"燕语报春",
		"action":
"$N吸一口气，手中连环七剑，一剑快似一剑，一式「燕语报春」，剑法轻灵飘逸，如风如雨般的攻向$n的$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
	([	"name":			"鹤影寒塘",
		"action":
"只见$N身形平平掠起，神情凄然，不经意间右手$w一抖，\n"
"一道剑虹将$n团团罩在其中，$w直奔$n的$l，这一招「鹤影寒塘」果然如诗如画",
		"dodge":		-20,
		"parry":		10,
		"damage":		20,
		"damage_type":		"刺伤"
	]),
        ([      "name":                 "孔雀开屏",
                "action":
"只见$N挽出十数朵剑花，化作十数道五彩剑虹将$n罩在其中，$n哪里识得这招「孔雀开屏」的利害",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "鹦鹉学舌",
                "action":
"$N突然脸色突变，神情滑稽，剑招变得与$n的招式一模一样！却又处处制住了你的招法，\n"
"眼见$N$w直奔$n的$l，$n却不知如何防备这招「鹦鹉学舌」",
                "dodge":                -5,
                "parry":                0,
                "damage":               20,
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "鸳鸯戏水",
                "action":
"$N纤腰微摆，长剑急刺，这一招「鸳鸯戏水」去势固然凌厉，抑且风姿绰约，直奔$n的$l",
                "dodge":                -10,
                "damage":               25,
                "damage_type":          "刺伤"
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
	int swo=(int)me->query_skill("bainiao-jian");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练百鸟剑法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练百鸟剑法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍百鸟剑法。\n", me);
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

