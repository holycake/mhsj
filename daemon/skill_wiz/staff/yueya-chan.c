//【月牙铲】yueya-chan.c 
inherit SKILL;

/*
月牙铲法    dodge  5    parry  -10    damage  25
月牙铲法使动开来甚为凶险，亦善于击破敌手防卫。缺点是
笨重异常。
*/

mapping *action = ({
        ([      "name":                 "",
                "action":
"$N一按$w后把，只见一道寒光闪过，$w便如灵蛇一般钻向$n的$l",
                "dodge":                0,
		"parry":	-20,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "",
                "action":
"$N手中$w一荡，使出一招「晓风残月」，$w带着森森冷气划向$n$l",
                "dodge":                0,
		"parry":	0,
                "damage":               25,
                "damage_type":  "割伤"
        ]),
        ([      "name":                 "",
                "action":
"$N手中的$w往地下一顿一弹，就在$n微一分神之时，$w已划出一道闪亮的弧光挑向$n$l",
                "dodge":                5,
		"parry":	-15,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "",
                "action":
"$N身形一转，手中$w往后一拖，就在这将退未退之际，$w一个转折呼！地一声向$n当头砸下",
                "dodge":                5,
		"parry":	-5,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "",
                "action":
"$N怪叫一声，$w一气乱舞势若疯虎地朝$n冲了过去，手中$w看似不成章法，实则暗藏凶险",
                "dodge":                0,
		"parry":	-15,
                "damage":               35,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "",
                "action":
"$N一抖$w，使了个「月黑风高」，手中的$w就象追魂的恶鬼一样缠上了$n的$l",
                "dodge":                0,
		"parry":	-15,
                "damage":               35,
                "damage_type":  "割伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法学月牙铲，等内力提高了再来吧。\n");

        if(  !(ob = me->query_temp("weapon"))
        ||     (string)ob->query("skill_type") != "fork" )
                return notify_fail("你必须先找一条钢叉才能学月牙铲。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="fork";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习月牙铲。\n");

	if(!environment(me)->query("cold"))
		return notify_fail("此地不够阴冷，再练有害无益。\n");

        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍月牙铲。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/yueya-chan/" + func;
}

