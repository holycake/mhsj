#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": HIW"$N使出"+HIR+"「埋头刀势」"+HIW+"，开左边门户，将左边身体向敌，饵$n"+HIW+"攻来，接着以$w"+HIW+"横拦，斜进右脚，换左手共持把，砍向\n"
                  "$n"+HIW+"的$l"NOR,
	    "force" : 300,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 300,
        "lvl"   : 0,
        "damage_type" : "砍伤",
        "skill_name" : "埋头刀势"
]),
([      "action": HIW"$N使出"+HIR+"「入洞刀势」"+HIW+"，开左边门户，侧身放空，饵$n"+HIW+"攻来，将$w自下撩起，进右步，单手自下而上斜撩$n"+HIW+"的$l"NOR,
	    "force" : 300,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 300,
        "lvl"   : 0,
        "damage_type" : "割伤",
        "skill_name" : "入洞刀势"
]),
([      "action": HIW"$N使出"+HIR+"「单撩刀势」"+HIW+"，开左边门户，侧身放空，饵$n"+HIW+"攻来,将$w"+HIW+"横揭起，斜进右步，单手自下而上斜撩$n"+HIW+"的$l"NOR,
	    "force" : 350,
        "attack": 350,
        "dodge" : 350,
        "parry" : 350,
        "damage": 350,
        "lvl"   : 0,
        "damage_type" : "割伤",
        "skill_name" : "单撩刀势"
]),
([      "action": HIW"$N使出"+HIR+"「腰砍刀势」"+HIW+"，单手撩起$w"+HIW+"，待势力已尽，归于左边，单手再复回，向$n"+HIW+"的$l横砍而去"NOR,
	    "force" : 400,
        "attack": 400,
        "dodge" : 400,
        "parry" : 400,
        "damage": 400,
        "lvl"   : 20,
        "damage_type" : "砍伤",
        "skill_name" : "腰砍刀势"
]),
([      "action": HIW"$N使出"+HIR+"「右独立刀势」"+HIW+"，开右边门户，将$w"+HIW+"往右后一搅，斜进右步为左独立，砍向$n"+HIW+"的$l"NOR,
	    "force" : 400,
        "attack": 400,
        "dodge" : 400,
        "parry" : 400,
        "damage": 400,
        "lvl"   : 20,
        "damage_type" : "砍伤",
        "skill_name" : "右独立刀势"
]),
([      "action": HIW"$N使出"+HIR+"「左独立刀势」"+HIW+"，开左边门户，将$w"+HIW+"往左后一搅，斜进右步，砍向$n"+HIW+"的$l"NOR,
	    "force" : 450,
        "attack": 450,
        "dodge" : 450,
        "parry" : 450,
        "damage": 450,
        "lvl"   : 30,
        "damage_type" : "砍伤",
        "skill_name" : "左独立刀势"
]),
([      "action": HIW"$N使出"+HIR+"「抝步刀势」"+HIW+"，左脚向前，开右边门户，待$n"+HIW+"攻来，则将$w"+HIW+"往右后一搅，进右脚，再进左脚，剪步斜入，\n"
				  "砍向$n"+HIW+"的$l"NOR,
	    "force" : 450,
        "attack": 450,
        "dodge" : 450,
        "parry" : 450,
        "damage": 450,
        "lvl"   : 30,
        "damage_type" : "砍伤",
        "skill_name" : "抝步刀势"
]),
([      "action": HIW"$N使出"+HIR+"「低看刀势」"+HIW+"，开右边门户，将$w"+HIW+"往右格，进右步于左边，绕到$n"+HIW+"的右后方劈下"NOR,
	    "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "lvl"   : 40,
        "damage_type" : "劈伤",
        "skill_name" : "低看刀势"
]),
([      "action": HIW"$N使出"+HIR+"「右提撩刀势」"+HIW+"，开左边门户，将$w"+HIW+"自下斜撩而上，进右步贴身劈向$n"+HIW+""NOR,
	    "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "lvl"   : 40,
        "damage_type" : "劈伤",
        "skill_name" : "右提撩刀势"
]),
([      "action": HIW"$N使出"+HIR+"「左定膝刀势」"+HIW+"，将$w"+HIW+"推出按于左膝上，退左步，饵$n"+HIW+"攻来，接着进左步于右步，已然绕到$n"+HIW+"的左后，向$n"+HIW+"砍下"NOR,
	    "force" : 550,
        "attack": 550,
        "dodge" : 550,
        "parry" : 550,
        "damage": 550,
        "lvl"   : 50,
        "damage_type" : "砍伤",
        "skill_name" : "左定膝刀势"
]),
([      "action": HIW"$N使出"+HIR+"「右定膝刀势」"+HIW+"，将$w"+HIW+"推出按于右膝上，饵$n"+HIW+"攻来。接着，$N"+HIW+"进左脚于右脚绕到$n"+HIW+"的身侧，砍下一刀"NOR,
	    "force" : 550,
        "attack": 550,
        "dodge" : 550,
        "parry" : 550,
        "damage": 550,
        "lvl"   : 50,
        "damage_type" : "劈伤",
        "skill_name" : "右定膝刀势"
]),
([      "action": HIW"$N使出"+HIR+"「朝天刀势」"+HIW+"，有意暴露左肩背胯脚，饵$n"+HIW+"来攻。$N"+HIW+"悬起左脚，将$w"+HIW+"往左一搅，随进右脚砍向$n"+HIW+""NOR,
	    "force" : 550,
        "attack": 550,
        "dodge" : 550,
        "parry" : 550,
        "damage": 550,
        "lvl"   : 50,
        "damage_type" : "砍伤",
        "skill_name" : "朝天刀势"
]),
});
int valid_enable(string usage) { return (usage == "blade") || (usage == "stick") || (usage == "spear") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 500)
        return notify_fail("你的内力修为不够。\n");

    if ((int)me->query_skill("force") < 100)
        return notify_fail("你的内功火候太浅。\n");

//    if ((int)me->query_skill("blade", 1) < (int)me->query_skill("dan-dao", 1))
//        return notify_fail("你的基本刀法水平有限，无法领会更高深的双手刀法。\n");
    return 1;
}
string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("dan-dao", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;

    if (! objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade"
    && (string)weapon->query("skill_type") != "stick"
    && (string)weapon->query("skill_type") != "spear")
        return notify_fail("你使用的武器不对。\n");

    if ((int)me->query("qi") < 60)
        return notify_fail("你的体力不够练双手刀法。\n");

    if ((int)me->query("neili") < 60)
        return notify_fail("你的内力不够练双手刀法。\n");

    me->receive_damage("qi", 45);
    me->add("neili", -43);
    return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/dan-dao/" + action;
}

