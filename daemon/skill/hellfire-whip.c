// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
//【烈火鞭】hellfire-whip.c

/*
烈火鞭    dodge  -10    parry  -10    damage  20
烈火鞭善缠绕攻敌，一旦被卷入其攻击范围则极难幸免，
且此鞭曲折转拐，来去无踪，要招架抵挡也甚为不易。
特点是杀伤不大。

Attention: 烈火鞭只有前六招，而第七，八两招是苦丧棒
和惊魂掌中，用来 Perform 的，而玩家平常并不会用到。
*/


inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "$N手腕一翻，一招",
        "长笑声中$N一个倒翻，使出",
        "$N使出",
        "$N喉咙里发出几声嚎叫，一式",
        "$N贴地而出，发出一招",
        "$N右手一引，一招",
});

string* skill_tail =({
        "，手中$w抖得笔直，带出一股锐啸猛刺$n$l",
        "，手中$w霹啪有声，一圈套一圈地卷向$n",
        "，手中$w绕了个圈，套向$n。",
        "，手中$w如长蛇一般，绕着$n转个不停",
        "，$w紧逼$n的$l",
        "，手中$w如夕阳的炊烟，袅袅不绝",
});

mapping *action = ({
        ([      "name":                 "地狱烈火",
                "action":
"$N手腕一翻，$w抖得笔直，带出一股锐啸猛刺$n$l",
                "dodge":                0,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":               
"$N大喝一声，手中$w宛若矫龙飞在半空，大有"+HIR"「横空出世」"NOR+"的气概。\n$n只觉得全身俱在$w笼罩之下",
                "dodge":                -20,
                "parry":                -20,
                "damage":               50,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"$N右手一引，$w贴地而飞，再疾卷而上，仿佛带着"+HIY"地狱中的烈火"NOR+"，夹头夹脑地扑向$n",
                "dodge":                -5,
                "parry":                -15,
                "damage":               35,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"也不知$N如何动了一动，但见长空中青光一闪，$n只觉$w已击上了$l",
                "dodge":                -15,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"$N身形往前滑出，手中$w霹啪有声，一圈套一圈地卷向$n",
                "dodge":                -5,
                "parry":                0,
                "damage":               35,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"长笑声中$N一个倒翻，手中$w急绞，但见方圆丈许飞沙走石，劲气纵横！\n$n不知如何才能脱困而出，脸都绿了",
                "dodge":                -15,
                "parry":                -20,
                "damage":               45,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "小楼夜哭",
                "action":
"$N喉咙里发出几声嚎叫，高举$w，不顾一切地冲向$n，几乎与$n贴脸而立！\n手中$w却悄无声息地刺向$n的$l，好厉害的「小楼夜哭」",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":        "秋坟鬼唱",
     "action":     "$N左手虚晃，右掌飘飘，掌心呈碧绿，一招"+HIM"「秋坟鬼唱」"NOR+"击向$n$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练烈火鞭。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("你必须先找一根鞭子才能练烈火鞭。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
   int i;
   mapping* m_actions;
   m_actions=me->query("skill_hellfire-whip");
   i=me->query("HellZhen");
   if( !me->query("HellZhen") ) {
   if(me->query("skill_hellfire-whip")==0) return action[random(6)];
     if(random(2)) return action[random(6)];
     return m_actions[random(sizeof(m_actions))];
   }else {
   return action[i];
   }
}
     

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习烈火鞭。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("你按着所学练了一遍烈火鞭。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("ghost") + "/hellfire-whip/" + func;
}



void skill_improved(object me)
{
   int m_skill=me->query_skill("hellfire-whip",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对烈火鞭的领悟加深了，你的烈火鞭进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对烈火鞭领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_hellfire-whip");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"抽伤"]);

   if(!arg||arg==" ")arg="烈火鞭秘技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_hellfire-whip",m_actions);
}
