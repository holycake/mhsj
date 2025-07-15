//Cracked by Roath

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "群魔乱舞",
                "action":
"$N手中$w一抖，晃出几个虚影，狂风骤雨般地向$n的$l连攻数剑",
		"parry":		0,
                "dodge":                -10,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "厉鬼缠身",
                "action":               "$N身形一转，暴喝一声，手中$w如一条银蛇般刺向$n的$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "百鬼夜行",
                "action":
"$N舞动$w，突然一个疾冲，$w挟着闪闪剑光刺向$n的$l",
		"parry":		0,
                "dodge":                -15,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "饿鬼拦路",
                "action":
"$N手中$w一抖，幻出几许银光，就在一恍惚间，$w已斜斜地点上了$n的$l",
		"parry":		-20,
                "dodge":                -20,
                "damage":               35,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "鬼影幢幢",
                "action":
"$N手中$w剑光暴长，又急又快地往$n$l刺去",
		"parry":		-10,
                "dodge":                -20,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "秋坟鬼唱",
                "action":
"$N猛然间身形一展，手中$w突发几尺剑芒，唰地刺向了$n的$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":               
"$N大喝一声，手中$w宛若矫龙飞在半空，大有「横空出世」的气概。\n$n只觉得全身俱在$w笼罩之下",
                "dodge":                -15,
                "parry":                -15,
                "damage":               30,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "小楼夜哭",
                "action":
"$N喉咙里发出几声嚎叫，高举$w，不顾一切地冲向$n，几乎与$n贴脸而立！\n手中$w却悄无声息地刺向$n的$l，好厉害的「小楼夜哭」",
                "dodge":                -10,
                "parry":                -10,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),


});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练追魂剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
	string name;
	mapping actions;

        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        actions=action[random(6)];
        }else {
        actions=action[i];
        }

	name=actions["name"];
	me->set_temp("kill_msg","special_msg");
	me->set_temp("special_msg",name);

	return actions;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习追魂剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍追魂剑法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("six-chaos-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/zhuihun-sword/" + func;
}


