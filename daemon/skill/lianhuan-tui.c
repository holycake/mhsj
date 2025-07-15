inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N左腿在前，右腿在后，双腿用力向$n的$l踢来",
                "dodge":                0,
                "parry":                10,
                "force":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左脚点地，身体向后旋转，右腿象疾风扫落叶般扫向$n的$l",
                "dodge":                -5,
                "parry":                0,
                "force":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右腿虚晃，左膝从意想不到的角度撞向$n的$l",
                "dodge":                -10,
                "parry":                -5,
                "force":                90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踢出三脚",
                "dodge":                -10,
                "parry":                -5,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N凌空跃起，身体向后急转，双脚从下往上一前一后地撩向$n的$l",
                "dodge":                0,
                "parry":                0,
                "force":                105,
                "damage_type":  "瘀伤"
        ]), 
        ([      "action":               
"$N忽然身形急转，瞻之在前，倏而在后，漫天腿影袭向$n的$l",
                "dodge":                -5,
                "parry":                -10,
                "force":                115,
                "damage_type":  "瘀伤"
        ]),

        ([      "action":               
"$N突然侧身，却步后退，一个前空翻，右脚自上而下，照$n的$l直劈下来",
                "dodge":                10,
                "parry":                -5,
                "force":                130,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N突然跃起，双足连环圈转，足带风尘，攻向$n的全身",
                "dodge":                10,
                "parry":                -15,
                "force":                140,
                "damage_type":  "瘀伤"
        ]), 
 
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
});

string *unarmed_parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

