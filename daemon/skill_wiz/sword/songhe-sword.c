//songhe.c by yushu 2000.10
/*
松鹤剑法    dodge  -5    parry  -5    damage  25
蜀山派镇山绝技，共六式：
*/

//苍松迎客　云谷鹤峰　青山隐隐　
//白鹤振羽　携手入云　退隐仙乡  

inherit SKILL;


mapping *action = ({
	([	"name":			"苍松迎客",
		"action":
"$N跳到空中,手中$w紧握，向$n劈去，都有似开山大刀一般，好一力道雄厚的「苍松迎客」",
		"dodge":		-10,
		"parry":		20,
		"damage":		25,
		"damage_type":		"劈伤"
	]),
	([	"name":			"云谷鹤峰",
		"action":
"只见$N左手辅剑，向空中舞剑，手中$w向$n的全身砍去\n"
"正是一招「云谷鹤峰」！",
		"dodge":		  24,
		"parry":		-19,
		"damage":		  25,
		"damage_type":		"砍伤"
	]),
        ([      "name":                 "青山隐隐",
                "action":
"$N飞身上前，手中$w疾舞，一招「青山隐隐」幻出团团剑芒，将$n紧紧裹在其中",
		    "dodge":		 -15,
                "parry":           -15,
                "damage":          35,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "白鹤振羽",
                "action":
"$N打到兴发，蓦地里一声清啸，手中$w急速向$n的$l刺去！这招山崩海啸般的「白鹤振羽」完全将$n惊呆了",
                "dodge":                15,
                "parry":                15,
                "damage":               35,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "携手入云",
                "action":
"只见$N单足离地，使出一招「携手入云」，手中$w急速飞进，劈出层层剑气，直向$n的$l劈去",
                "dodge":                -10,
                "parry":                -10,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "退隐仙乡",
                "action":
"$N快速前进，一式「退隐仙乡」，身随剑起，向$n全身环出多初剑芒，招招势若飞龙卷身，$n哪里闪避得过",
		"dodge":	          -15,
		"parry":		15,
		"damage":		20,
		"damage_type":		"刺伤"
	])
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，无法学习松鹤剑法。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("songhe-sword");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练松鹤剑法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练松鹤剑法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍松鹤剑法。\n", me);
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
        return CLASS_D("shushan") + "/songhe-sword/"+func;
}

