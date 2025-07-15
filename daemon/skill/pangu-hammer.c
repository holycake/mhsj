inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N左手化出一个圆圈，右手中的$w一招",
        "$N一弹手中的$w，一招",
        "$N暴喝一声，腾空飞起，以泰山压顶之式扑下，手中的$w带着轰轰\n雷声，一招",
        "$N一抖手中$w，使出",
        "$N手中的$w一转，一招",
        "$N一抖手中的$w，一招",
        "$N身形微顿，一招",
        "$N手中$w从下往上急挥，一招",  
        "$N凌空三连翻，一招",
        "$N挥动$w，从左划右，一招",                               
});

string* skill_tail =({
        "，向$n的$l挥去",
        "，手中的$w向$n的$l雷霆般地砸下",
        "，狠狠击向$n的$l",
        "，从四面八方盖向$n的$l",
        "，幻出一片刀光剑影，虚虚实实的挥向$n的$l",
        "，$w猛的砸向$n的$l",
        "，$w从偏锋击向$n的太阳大穴",
        "，$w拐了个弯般击向$n的后脑",
});

mapping *action = ({
        ([      "action":               
"$N左手化出一个圆圈，右手中的$w一招「威镇四方」向$n的$l挥去", 
     "dodge":     10,
     "parry":     -10,
     "damage":     35,
     "damage_type":   "砸伤"
        ]),
        ([      "action":               
"$N一弹手中的$w，一招「气盖山河」，手中的$w向$n的$l雷霆般地砸下", 
     "dodge":     0,
     "parry":     -20,
     "damage":     50,
     "damage_type":   "砸伤"
        ]),
        ([      "action":               
"$N暴喝一声，腾空飞起，以泰山压顶之式扑下，手中的$w带着轰轰雷声一招"HIG"「千钧一发」"NOR"击向$n的$l", 
     "dodge":   10,
     "parry":   -20,
     "damage":   45,
     "damage_type":   "砸伤",
        ]),
        ([      "action":               
"$N手中的$w一转，一招「狂风暴雨」从四面八方盖向$n的$l", 
     "dodge":   0,
     "parry":   -25,
     "damage":   50,
     "damage_type":   "挫伤",
        ]),
        ([      "action":
"$N一抖手中的$w，一招「夏日狂阳」幻出一片刀光剑影，虚虚实实的挥向$n的$l", 
     "dodge":   10,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "挫伤",        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 55 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;
        int flvl=(int)me->query_skill("force");
        int slvl=(int)me->query_skill("hammer");        

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("你必须先找一个锤或者是类似的武器，才能练盘古九式。\n");

        if( (int)me->query("kee") < 40
        ||      (int)me->query("force") < 4 )        
                return 
notify_fail("你的体力或内力不够练盘古九式，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
        if(random(slvl)>flvl)
                me->improve_skill("force", 1);        
        return 1;
} 
int valid_effect(object me, object weapon, string name, int skill)
{
}
 
string *parry_msg = ({
        "$n后退一步，一招「荡气回肠」猛的砸向$N。\n",
        "$n身形微顿，一招「围韩救赵」反捣$N的必救之处。\n",
        "$n手中兵器从下往上急挥，一招「恶鬼还阳」磕开了$N手中的$w\n",
});

string *unarmed_parry_msg = ({
        "$n一招「钟鼓齐鸣」，从偏锋击向$N的太阳大穴。\n",
        "$n挥动兵器，从左划右，一招「横扫千军」封住了$N的攻势。\n",
        "$n凌空三连翻，一招「披沙拣金」反击$N的后脑，逼得$N中途撤招。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


