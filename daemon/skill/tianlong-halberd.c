// 神话世界・西游记・版本（世纪）
/* <SecCrypt CPL V3R05> */
 
//【天龙戟】tianlong-halberd.c
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N使一招",
        "$N使出天龙戟法中的",
        "只见$N手中$w一式",
        "$N大喝一声，一招",
        "$N的$w虚点，蓦地进步跟身，一招",
        "$N手中$w一递，戟身竟如残月般弯转，一招",
        "$N将手中的$w舞得密不透风，一招",                      
});

string* skill_tail =({
        "，手中$w一抖，化出无数枪头，直刺$n的$l",
        "，手中$w晃动，虚点数枪，突然自影中一戟刺向$n的$l",
        "，向前猛窜，手中$w反背一戟，直扎$n的$l",
        "，手中$w枪头乱抖，铺天盖地杀来，招招不离$n的$l",
        "，从$n意想不到的地方刺向$n的$l",
        "，反手对准$n$l削去",
        "，迫得$N连连后退",
});

mapping *action = ({
        ([      "action":               
"$N使一招「诸皆成梦」，手中$w一抖，化出无数枪头，直刺$n的$l",
                "dodge":                15,
                "parry":                -10,
                "damage" :              15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出天龙戟法中的「大悲天龙」，手中$w晃动，虚点数枪，突然自影中一戟刺向$n的$l",
                "dodge":                10,
                "parry":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一招「天龙摆尾」，向前猛窜，手中$w反背一戟，直扎$n的$l",
                "dodge":                20,
                "parry":                -5,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w一式「天龙行空」，手中$w枪头乱抖，铺天盖地杀来，招招不离$n的$l",
                "damage":                15,
                "dodge":                10,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w虚点，蓦地进步跟身，一招「观物达观」刺向$n的$l",
                "dodge":                15,
                "parry":                -30,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w一递，戟身竟如残月般弯转，一招"HIG"「一念回光」"NOR"反手对准$n$l削去",
                "dodge":                0,
                "parry":                -10,
                "damage":               45,
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练天龙戟法。\n");

        if( !(ob = me->query_temp("weapon"))
   ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一把戟才能练戟法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="halberd" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
   mapping* m_actions;

   if(me->query("skill_tianlong")==0) return action[random(sizeof(action))];
   if(random(6)>1) return action[random(sizeof(action))];
   
   m_actions=me->query("skill_tianlong");
   return m_actions[random(sizeof(m_actions))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习天龙戟法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍天龙戟法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xuyi") + "/tianlong-halberd/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出一招「过眼烟云」，荡开了$N的$w。\n",
        "$n使出「天龙狂舞」，将$N的$w封于丈外。\n",
        "$n手中的画戟一抖，一招「久历歧途」，向$N拿$w的手腕刺去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的画戟舞得密不透风，一招「荆榛丛中」封住了$N的攻势。\n",
        "$n反手一招「云浮华相」，整个人消失在一团光芒之中。\n",
        "$n使出一招「光万境闲」，直刺$N的双手，迫得$N收招。\n",
        "$n将手中的画戟一抖，一招「天涯空驰」，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("tianlong-halberd",1);

   if(m_skill>200&&m_skill%20==0){
     tell_object(me,HIY"你对天龙戟法的领悟加深了，你的天龙戟法进入了一个新的境界！\n"NOR);
     if(me->query("tianlong/times")>2){
        tell_object(me,HIW"然而你的天龙戟法已经练至顶峰，不能再创出新招了。\n"NOR);
        return;
     }

     if(random(me->query_kar())<17){
        tell_object(me,HIW"然而你的心中却泛起淡淡的失落。\n"NOR);
        return;
     }
     if((random(me->query("int")/2)+(int)me->query_skill("literate")/50)<10){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，领悟出了天龙戟法新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   string *banned_name = ({
                "你", "你", "我", "他", "她", "它", "爸", "妈",
                "爷", "奶", "巫师", "天神", "小胖", "逝影", "夜辰", "神仙",
        });

   mapping* m_actions;
   mapping m_act=([]);
   int content, i=strlen(arg);
   string msg;

   m_actions=me->query("skill_tianlong");
   if(!pointerp(m_actions)) m_actions=({});

     if (!arg || arg=="") 
     {
          tell_object(me,"请为你的新招式取一个名字：");
          input_to( (: call_other, __FILE__, "name_skill", me:));
          return;
     }
     else while(i--) 
     {
                if( arg[i]<=' ' ) 
                {
                        tell_object(me,"招式名字不能使用控制字元，请重新设定一个名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if(strsrch(arg, "　") >= 0) 
                {
                        tell_object(me,"招式名字不能有空格，请重新设定一个名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) 
                {
                        tell_object(me,"请您用「中文」为你的新招式取名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
     }
     if( member_array(arg, banned_name)!=-1 ) 
     {
     tell_object(me,"对不起，这种名字会造成其他人的困扰。请重新设定一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
     if( (strlen(arg) < 8) || (strlen(arg) > 16 ) ) 
     {
     tell_object(me,"对不起，招式名字必须是 ４ 到 ８ 个中文字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
            
   content=(me->query("str")+me->query_skill("unarmed",1)/10)*2;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=(me->query("con")+me->query_skill("force",1)/10)*2;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   m_act+=(["name": arg ]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+HIG+arg+NOR"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_tianlong",m_actions);
   me->add("tianlong/times",1);
}

