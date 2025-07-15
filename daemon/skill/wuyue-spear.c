//wuyue-spear 五岳神枪greenwc

//wuyue-spear 五岳神枪greenwc

//wuyue-spear 五岳神枪greenwc

//wuyue-spear 五岳神枪greenwc

//wuyue-spear 五岳神枪greenwc

//wuyue-spear 五岳神

/*

五岳神枪    dodge  0    parry  -10    damage  25

开国武成王黄飞虎的成名枪法，有百折不会之势

令人难以招架，威力也不可小视

*/

inherit SKILL;

mapping *action = ({

        ([      "action":

"$N使一招「泰山压顶」，手中$w向$n劈头改脑直扫了下来",

                "damage":               30,

                "dodge":                15,

                "parry":                -15,

                "damage_type":  "刺伤"

        ]),

        ([      "action":

"$N运足精神，抖起$w，一招「华岳插云」挑向$n$l",

                "damage":               30,

                "dodge":                5,

                "parry":                -10,

                "damage_type":  "刺伤"

        ]),

        ([      "action":

"$N手中$w势若飞瀑刺向$n的$l，好一招「衡峰溪绕」",

                "damage":               15,

                "dodge":                -10,

                "parry":                -10,

                "damage_type":  "刺伤"

        ]),

        ([      "action":

"$N 一口气抖出五朵枪花，暗喝一声「五岳朝宗」。枪枪不离$n要害",

                "damage":               30,

                "dodge":                -10,

                "parry":                -15,

                "damage_type":  "刺伤"

        ]),

        ([      "action":

"只见$N一个虎跳使个「太室参佛」，手中$w带出一道利闪直奔$n$l",

                "damage":               20,

                "dodge":                0,

                "parry":                0,

                "damage_type":  "刺伤"

        ]),

        ([      "action":

"只见$N腾空飞气，人枪合一，$w只落$n$1，正是一招「恒岭悬空」",

                "damage":               15,

                "dodge":                5,

                "parry":                -25,

                "damage_type":  "刺伤"

        ]),

});

int valid_learn(object me)

{

        object ob;

        if( (int)me->query("max_force") < 100 )

                return

notify_fail("你的内力不够，没有办法练五岳神枪。\n");

        if( !(ob = me->query_temp("weapon"))

        ||      (string)ob->query("skill_type") != "spear" )

                return notify_fail("你必须先找一柄枪才能练枪法。\n");

        return 1;

}

int valid_enable(string usage)

{

        return (usage=="spear") || (usage=="parry");

}

mapping query_action(object me, object weapon)

{

        return action[random(sizeof(action))];

}

int practice_skill(object me)

{

        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))

        ||      (string)weapon->query("skill_type") != "spear" )

                return

notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");

        if( (int)me->query("kee") < 30 

        ||    (int)me->query("force") < 5  )

                return

notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");

        me->receive_damage("kee", 30);

        me->add("force", -5);

        write("你按着所学练了一遍五岳神枪。\n");

        return 1;

}

string perform_action_file(string func)

{

return CLASS_D("yaomo") + "/kusong/wuyue-spear/" + func;

}

