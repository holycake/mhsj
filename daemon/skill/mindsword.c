//Cracked by Roath

#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "action":       "$N使一招「落英缤纷」，身形向上飘起，手中$w虚虚实实幻出万点剑花纷纷扬扬撒向$n$l",
        "damage":        20,
        "damage_type":  "刺伤"
        ]),
    ([  "action":       "$N舞动$w，一式「人面桃花」，左手向$n面门一晃，右手$w抖出几朵剑花挟着虎虎剑气刺向$n的$l",
        "damage":        25,
        "damage_type":  "刺伤"
    ]),
    ([ "action":        "$N身形绕$n一转，手中$w望空一指，一式「急风骤雨」幻出满天剑影，向$n$l接连挥出数剑",
        "damage":        20,
                "damage_type":  "割伤"
        ]),
    ([  "action":       "$N身形飘然而起，在半空中身子一旋，悠然一式「江城飞花」手中$w若有若无淡淡刺向$n的$l",
        "damage":       20,
                "damage_type":  "刺伤"
        ]),
    ([  "action":       "$N纵起丈余，一式「细云巧翻胸」头下脚上，一招「万花齐落」手中$w舞成一个光球罩向$n的$l",
        "damage":       40,
        "damage_type":  "刺伤"
    ]),
    ([  "action":       "$N一声大喝使出「漫天花雨」，手中$w幻出漫天花瓣，迅若奔雷射向$n的$l",
        "damage":       30,
        "damage_type":  "刺伤"
    ]),
    ([  "action":    "$N轻叹一声，手中$w怀中一抱，一时「落花无意」，$w锵然跃出倏的化作几点带露的桃花，飘然飞向$n的$l",
        "damage":       40,
        "damage_type":  "刺伤"
    ]),

});

int valid_learn(object me)
{
        object ob;

    if( (int)me->query_skill("zixia-shengong",1) < 50)
        return notify_fail("你的紫霞神功火候还不够。\n");

if( (int)me->query_skill("yujianshu",1) < 50)
return notify_fail("你的御剑术火候还不够。\n");

    if( (int)me->query("max_force") < 300 )
        return notify_fail("你的内力不够，不能练心剑。\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能学习剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object ob;

    if( (int)me->query("kee") < 30
    ||  (int)me->query("force") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习心剑。\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能习练剑法。\n");

    me->receive_damage("kee", 30);
        me->add("force", -5);
    write("你按著所学练了一遍心剑。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") + "/mindsword/" + action;
}
