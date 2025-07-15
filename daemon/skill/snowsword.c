
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowsword. 【风回雪舞剑法】

/*
风回雪舞剑法    dodge  -20    parry  -10    damage  15
此剑法迅急若风回，轻灵似雪舞，敌手极难躲闪招架，多为
气短力弱之女子所喜。
*/

// 寒芳留照魂应驻，碗凝深翠拂平沙
// 攒花染出几霜痕，霜印传神梦也空
// 篱筛破落锁玲珑，暗香浮动影黄昏
// 风波不信菱枝弱
inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N不闪不避，一式",
        "$N使出",
        "$N妍然一笑，一式",
        "$N一个急转，使出",
});
string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w化为一道金光罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，顿时一阵幽香飘向$n",
});

mapping *action = ({
   ([   "action":
"$N使一招"+HIB"「寒芳留照魂应驻」"NOR+"，手中$w化为一道疾光刺向$n的$l",
     "dodge":     -5,
                "parry":                -10,
     "damage":     30,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"只见$N半个急转，使出"+HIG"「晚凝深翠拂平沙」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
     "dodge":     -35,
                "parry":                -5,
     "damage":     30,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N淡淡一笑，一式"+HIY"「攒花染出几霜痕」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
     "dodge":     -10,
                "parry":                -15,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中$w轻轻一抖，一式"+HIW"「霜印传神梦也空」"NOR+"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
     "dodge":     -30,
                "parry":                -5,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中$w再一抖，只见寒光点点，飘浮不定。\n这一招"+HIR"「篱筛破月锁玲珑」"NOR+"只看得$n眼花缭乱，哪里还能招架",
     "dodge":     -20,
                "parry":                -20,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
        ([      "action":
"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式"+MAG"「暗香浮动月黄昏」"NOR,  
                "dodge":                -35,
                "parry":                -5,
                "damage":           40, 
                "damage_type":  "刺伤"
        ]),
   ([      "action":
"$N不闪不避，一式"+HIC"「风波不信菱枝弱」"NOR+"，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "dodge":                -5,
                "parry":                -10,
                "damage":          30,
                "damage_type":  "刺伤"
        ]),
   
 ([ "name": "花前月下",
     "action":
HIC"$N一招「花前月下」,左剑自上而下搏击,模拟冰轮横空,清光铺地的光景.\n"
"右剑却是不住颤动,如鲜花招展风中,来回挥削,只晃得$n眼花撩乱."NOR,
      "dodge": -80,
      "parry": -50,
      "damage": 150,
     "damage_type": "刺伤"
]),
});

int valid_learn(object me)
{
   object ob;
if( (string)me->query("gender") !="女性")
return notify_fail("风回雪舞剑只有女子才能学习!!\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练风回雪舞剑法。\n");

   if( (string)me->query_skill_mapped("force")!= "moonforce")
     return notify_fail("风回雪舞剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
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
 mapping* m_actions;
 i=me->query_action("SS_perform");
 if( ! me->query_temp("SS_perform"))
      {
     if(me->query("skill_snowsword")==0) return action[random(7)];
     if(random(2))return action[random(7)];
     m_actions=me->query("skill_snowsword");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
   {
  return action[7];
  }
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{if( (string)me->query("gender") !="女性")
 return notify_fail("风回雪舞剑法只有女子才能练习!!\n");
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习风回雪舞剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write("你按著所学练了一遍风回雪舞剑法。\n");
   return 1;
}


string perform_action_file(string func)
{
return CLASS_D("moon") + "/snowsword/" + func;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("snowsword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对风回雪舞剑的领悟加深了，你的风回雪舞剑进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对风回雪舞剑领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_snowsword");
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

   if(!arg||arg==" ")arg="风回雪舞剑必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_snowsword",m_actions);
}
 
