// xuantian-zhi.c
inherit SKILL;

mapping *action = ({
([      "action" : "$N左指挥出，一式「黯然消魂」，削向$n的掌缘",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "黯然消魂",
        "damage_type" : "刺伤"
]),
([      "action" : "$N全身之力聚于一指，一式「天似无情」，指向$n的胸前",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "天似无情",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌贴于神道穴，右手一式「情根深种」，向$n的$l划过",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "情根深种",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双目怒视，一式「情在天涯」，双指拂向$n的额、颈、肩、臂、胸
、背",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "情在天涯",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「独饮情伤」，左掌掌心向外，右指蓄势点向$n的$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "独饮情伤",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手伸出，十指叉开，一式「无诉别情」，小指拂向$n的太渊穴",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "无诉别情",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双迸出无数道劲气，一式「情意绵绵」射向$n的全身",
        "force" : 400,
        "dodge" : 25,
        "damage": 120,
        "lvl" : 80,
        "skill_name" : "情意绵绵",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练玄天无情指必须空手。\n");
//        if ((int)me->query_skill("wuzheng-xinfa", 1) < 80)
//                return notify_fail("你的无争心法火候不够，无法学玄天无情指。\n");
        if ((int)me->query("max_force") < 300)
                return notify_fail("你的内力太弱，无法练玄天无情指。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xuantian-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("gin") < 30)
                return notify_fail("你的精太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练玄天无情指。\n");
        me->receive_damage("gin", 30);
        me->add("force", -10);
        return 1;
}

