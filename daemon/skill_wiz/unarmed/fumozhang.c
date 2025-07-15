//fumozhang.c 【伏魔掌】by yushu@SHXY
//2000/11
inherit SKILL;

mapping *action = ({
        ([      "action":
"$N前腿踢出，后腿脚尖点地，一式「伏魔天下」，二掌直出，攻向$n的上中下三路",
                "dodge":                -5,
                "parry":                -5,
	          "force":		80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N左掌划一半圆，一式「铁血丹心」，右掌斜穿而出，疾拍$n的胸前大穴",
                "dodge":                -25,
                "parry":                -25,
	         "force":		70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使一式「荡尽群魔」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N左掌护胸，右拳凝劲后发，一式「横空出世」，缓缓推向$n的$l",
                "dodge":                5,
                "parry":                5,
	         "force":		100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使一式「力拔千钧」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
                "dodge":                -5,
                "parry":                -5,
	         "force":		90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N合掌抱球，猛吸一口气，一式「群魔伏首」，双掌疾推向$n的肩头",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练伏魔掌必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
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

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("shushan") + "/fumozhang/" + func;
}


