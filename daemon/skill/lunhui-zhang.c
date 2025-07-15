
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
//【轮回杖】lunhui-zhang.c
inherit SKILL;

/*
轮回杖    dodge  5    parry  -10    damage  25
佛门看家武功，用意于以杀止杀，杖沉力猛，杀伤不弱。
*/
#include <ansi.h>;
string* skill_head =({
        "$N口宣佛号，面色庄严，一招",
        "$N断喝一声，使出一式",
        "$N发出一招",
        "$N轻轻一纵，一式",
        "$N镇定自若，一招",
        "$N面露霞光，使出一招",
});
string* skill_tail =({
        "，手中$w长驱直入，迳刺$n$l",
        "，手中$w若隐若现的砸向$n",
        "，直逼$n",
        "，手中$w若有千斤，直逼$w。",
        "，轻轻一纵，手中$w直点$n的$l",
        "，$n顿时手忙脚乱，$w就要落到$l上",
});

mapping *action = ({
        ([      "name":                 "报应不爽",
                "action":
"$N口宣佛号，面色庄严，一招「报应不爽」手中$w长驱直入，迳刺$n$l",
                "dodge":                -10,
     "parry":               -5,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "大限将至",
                "action":
"$N手中$w一荡，使出「大限将至」，但见一道杖影隐隐约约，若有若无地向$n压下",
                "dodge":                15,
      "parry":               -15,
                "damage":               40,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "回头是岸",
                "action":
"只见$N手中$w疾横，斗地点出！这招「回头是岸」轻灵飘逸，\n$n眼见杖风袭来，竟不知如何是好",
                "dodge":                20,
     "parry":               -20,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "在劫难逃",
                "action":
"$N大喝一声，手中$w向$n兜头击落，兵器未至，已将$n各处退路封死，好一招「在劫难逃」",
                "dodge":                -5,
     "parry":               0,
                "damage":               50,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "天网恢恢",
                "action":
"$N倒提$w，轻轻一纵，一招「天网恢恢」从$n意想不到的地方刺出，$n顿时手足无措，狼狈万分",
                "dodge":                -10,
     "parry":               -5,
                "damage":               35,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "再堕轮回",
                "action":
"$N脸上突现煞气，举起手中$w，猛向$n$l击落，这招「再堕轮回」出手又快又狠",
                "dodge":                20,
     "parry":               -15,
                "damage":               55,
                "damage_type":  "砸伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法学轮回杖，等内力提高了再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("你必须先找一条禅杖才能学轮回杖。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_lunhui-zhang");
     if(me->query("skill_lunhui-zhnag")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("force") < 5 )
                return
notify_fail("你的内力或气不够，没有办法练习轮回杖。\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
        write("你按着所学练了一遍轮回杖。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/lunhui-zhang/" + func;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("lunhui-zhang",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对轮回杖的领悟加深了，你的轮回杖进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对轮回杖领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_lunhui-zhang");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);

   if(!arg||arg==" ")arg="轮回杖必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_lunhui-zhang",m_actions);
}
 
