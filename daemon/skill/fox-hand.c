// SKILL zhemei-shou.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「狐假虎威」，双手横挥，抓向$n",
        "force" : 80,
        "dodge" : 20,
        //"damage" :10,
        "lvl" : 0,
        "skill_name" : "狐假虎危",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「狐行千里」，身子跃然而起，抓向$n的头部",
        "force" : 100,
        "dodge" : 20,
        //"damage" : 20,
        "lvl" : 10,
        "skill_name" : "狐行千里",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「飞狐一现」，双手纷飞，$n只觉眼花缭乱",
        "force" : 90,
        "dodge" : 30,
        //"damage" : 30,
        "lvl" : 30,
        "skill_name" : "飞狐一现",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「灵狐飞天」，双手合击，$n只觉无处可避",
        "force" : 100,
        "dodge" : 30,
        //"damage" : 45,
        "lvl" : 40,
        "skill_name" : "灵狐飞天",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「白狐献宝」，双手飘然抓向$n",
        "force" : 100,
        "dodge" : 30,
        //"damage" : 50,
        "lvl" : 50,
        "skill_name" : "白狐献宝",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N一招「双狐合击」，拿向$n，似乎$n的全身都被笼罩",
        "force" : 150,
        "dodge" : 30,
       // "damage" : 100,
        "lvl" : 70,
        "skill_name" : "双狐合击",
        "damage_type" : "内伤"
]),

([      "action" : "$N左手虚晃，右手一记「仙狐谢恩」击向$n的头部",
        "force" : 150,
        "dodge" : 30,
        //"damage" : 150,
        "lvl" : 80,
        "skill_name" : "仙狐谢恩",
           "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("fox-hand",1);
if (level) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
   return action[0];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练狐手。\n");
        me->receive_damage("kee", 25);
        me->add("force", -10);
        return 1;
}



