//Cracked by Roath

// hunyuan-zhang.c 混元掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「白云出岫」，双掌间升起一团淡淡的白雾，缓缓推向$n的$l",
        "force" : 80,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N并指如剑，一式「白虹贯日」，疾向$n的$l戳去",
        "force" : 80,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「云断秦岭」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
        "force" : 90,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双掌隐隐泛出青气，一式「青松翠翠」，幻成漫天碧绿的松针，雨点般向$n击去",
        "force" : 100,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形往上一纵，使出一式「天绅倒悬」，双掌并拢，笔直地向$n的$l插去",
        "force" : 60,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一变，使一式「无边落木」，双掌带着萧刹的劲气，猛地击往$n的$l",
        "force" : 80,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「高山流水」，左掌凝重，右掌轻盈，同时向$n的$l击去",
        "force" : 120,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N突地一招「金玉满堂」，双掌挟着一阵风雷之势，猛地劈往$n的$l",
        "force" : 100,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「风伴流云」，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
        "force" : 110,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「烟雨飘渺」，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪",
        "force" : 80,
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" ; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练混元掌必须空手。\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("你的紫霞神功火候不够，无法学混元掌。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练混元掌。\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 40)
                return notify_fail("你的内力不够练混元掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") +"/hunyuan-zhang/" + action;
}