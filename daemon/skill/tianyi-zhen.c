// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */


inherit SKILL;

#include <ansi.h>;

string* skill_head =({
        "[31m$N捏着手中的$w，一招[m",
        "[32m$N手中的$w一抖，一式[m",
        "[33m$N一推手中的$w，使出[m",
        "[34m$N手中的$w若隐若现，使出一式[m",
        "[35m$N手中$w如飞，使出一招[m",
        "[36m$N手中$w一沉，一式[m",
     });

string* skill_tail =({
        "[31m，刺向$n的$l。[m",
        "[32m，对$n的$l疾刺过去。[m",
        "[33m，居然抡成了一个圆，罩向$n的全身。[m",
        "[34m，刺向$n的要害部位。[m",
        "[35m，深深的刺进了$n的$l[m",
        "[36m，$w向$n急速飞去。[m",
});

mapping *action = ({
([      "action" : "$N捏着手中的$w，一招「神针刺脉」，刺向$n的$l。",
        //"force" : 120,
        "dodge" : -10,
        "parry" : 5,
        "damage" : 45,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一抖，$w发出一道悬目的光芒，刺向$n的要害。",
        //"force" : 130,
        "dodge" : -10,
        "parry" : 10,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N轻轻一推手中$w，就见$w向$n疾刺过去。",
        //"force" : 140,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 55,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w若隐若现，突然就见$w向$n的要害刺去。",
        //"force" : 160,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w一沉，$w似乎有千钧重，直向$n压下。",
        //"force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 65,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中一个小小的$w居然抡成了一个圆，罩向$n的全身。",
        //"force" : 210,
        "dodge" : -15,
        "parry" : 15,
        "damage" : 75,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w一闪，$n顿时觉得迷惑不解，同时就见$w已经贴近了$n的$l。",
        //"force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N大吼一声，$w如飞，只见$n的$l就要被$w刺到。",
        //"force" : 280,
        "dodge" : -20,
        "parry" : 10,
        "damage" : 60,
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return (usage == "unarmed") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("xuanhu-xinfa", 1) < 20)
                return notify_fail("你的玄狐心法火候太浅。\n");
        if ((int)me->query_skill("fox-hand", 1) < 20)
                return notify_fail("你的狐手火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_tianyi-zhen");
     if(me->query("skill_tianyi-zhen")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
            object ob;

    if(!objectp(ob=me->query_temp("weapon"))
|| (string)ob->query("skill_type") != "unarmed")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练天一针法。\n");
        me->receive_damage("kee", 30);
        return 1;
}

string perform_action_file(string action)
  { return CLASS_D("xuanyuan")+"/tianyi-zhen/"+action;}

void skill_improved(object me)
{
   int m_skill=me->query_skill("tianyi-zhen",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对天一神针的领悟加深了，你的天一神针进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对天一神针领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_tianyi-zhen");
   if(!pointerp(m_actions))m_actions=({});
   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="天一神针绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_tianyi-zhen",m_actions);
}
