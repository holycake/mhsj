//by night

#include <ansi.h>
 
inherit SKILL;

string* skill_head =({
        "$N使一招",
        "$N手中的$w一招",
        "$N舞动$w，一招",
        "$N一抖手中$w，使出",
        "$N手中$w剑光四散，一招",
        "$N微微垂首，情思切切，一招",
        "$N手中$w斜斜指出，招演",
        "$N轻叹一声，飘身后撤，眉间眼角离愁楚楚。$n正要追击，$N忽然使出一\n招",  
        "$N将$w一抖，使出一招",
        "$N掌中剑飘忽不定，一招",
        "$N虚晃一剑，身随剑势，在空中盘旋，一招",                               
});
string* skill_tail =({
        "，手中$w如和煦春风洒向$n的$l，剑光点点，仿若\n柳絮扬扬，$n竟看不出这一招的来势",
        "，轻如飞花，薄如晓雾，仿佛无尽愁绪，无孔\n不入地刺向$n的$l",
        "，剑如飞星，人如闪电，人剑合一，化为一道\n势若飞瀑般的银光，刺向$n的$l",
        "，以情驭剑，剑势缠绵悱恻，缓缓指向\n$n的$l。$n明明见到$w的来势，但变换了无数方位，却都躲不开$N剑网纠缠",
        "，剑光如云，剑尖一点清明仿佛绣花\n针般纤纤无定，在$n的$l周围来回穿梭。$n眼花缭乱，不知该如何抵挡",
        "，$w幻出万点银光，绵长如梦，亦\n幻亦真。$n一时间不知道自己是在梦中还是身处现实，几乎痴了过去",
        "，霎时间银光闪烁，$w幻做点点繁\n星，耀目生辉。$n只觉自己身处在一片银亮的光河中，满眼剑气银光交相纵横",
        "，手中$w泛出万道光华，疾指$n的$l",
        "，剑掌连环，将$n全身团团罩住",
        "，手中剑急如骤雨般地刺向$n，迫得$n不得不回招自护",
        "，掌中剑光芒陡长，剑光自远而近，荡开了$n的兵刃",
});
 
mapping *action = ({
        ([      "name":                 "春风乍起",
                "action":               "$N使一招「春风乍起」，手中$w如和煦春风洒向$n的$l，剑光点点，仿若\n"
"柳絮扬扬，$n竟看不出这一招的来势", 
    "dodge":     -10,
     "parry":      0,
     "damage":     30,
     "damage_type":     "刺伤"
   ]),
        ([      "name":                 "细雨绵绵",
                "action":               "$N手中的$w一招「细雨绵绵」，轻如飞花，薄如晓雾，仿佛无尽愁绪，无孔\n"
"不入地刺向$n的$l", 
     "dodge":     -5,
     "parry":      0,
     "damage":     25,
     "damage_type":     "刺伤"
   ]),
        ([      "name":                 "飞星传恨",
                "action":               "$N舞动$w，一招「飞星传恨」，剑如飞星，人如闪电，人剑合一，化为一道\n"
"势若飞瀑般的银光，刺向$n的$l", 
     "dodge":     -10,
     "parry":     -5,
     "damage":     35,
     "damage_type":     "刺伤"
   ]),
        ([      "name":                 "柔情似水",
                "action":               "$N一抖手中$w，使出「柔情似水」，以情驭剑，剑势缠绵悱恻，缓缓指向\n"
"$n的$l。$n明明见到$w的来势，但变换了无数方位，却都躲不开$N剑网纠缠", 
     "dodge":     10,
     "parry":     -20,
     "damage":     35,
     "damage_type":     "刺伤"
        ]),
        ([      "name":                 "纤云弄巧",
                "action":               "$N手中$w剑光四散，一招「纤云弄巧」，剑光如云，剑尖一点清明仿佛绣花\n"
"针般纤纤无定，在$n的$l周围来回穿梭。$n眼花缭乱，不知该如何抵挡", 
     "dodge":     -15,
     "parry":     -20,
     "damage":     30,
     "damage_type":     "刺伤"
        ]),
        ([      "name":                 "佳期如梦",
                "action":               "$N微微垂首，情思切切，一招「佳期如梦」，$w幻出万点银光，绵长如梦，亦\n"
"幻亦真。$n一时间不知道自己是在梦中还是身处现实，几乎痴了过去", 
     "dodge":     -10,
     "parry":      0,
     "damage":     35,
     "damage_type":     "割伤"
        ]), 
        ([      "name":                 "银汉迢迢",
                "action":               "$N手中$w斜斜指出，招演「银汉迢迢」，霎时间银光闪烁，$w幻做点点繁\n"
"星，耀目生辉。$n只觉自己身处在一片银亮的光河中，满眼剑气银光交相纵横",
     "dodge":     0,
     "parry":     -10,
     "damage":     40,
     "damage_type":     "割伤"
        ]), 
        ([      "name":                 "鹊桥归路",
                "action":               "$N轻叹一声，飘身后撤，眉间眼角离愁楚楚。$n正要追击，$N忽然使出一\n"
"招「"+HIG"鹊桥归路"NOR+"」，手中$w泛出万道光华，疾指$n的$l",
     "dodge":     0,
     "parry":     5,
     "damage":     this_player()->query("sword")/8+10,
     "damage_type":     "刺伤"
        ]),
});
int valid_learn(object me)
{
   object ob;

   if( (string)me->query("gender") != "女性" )
     return notify_fail("七夕剑法是只有女子才能练的武功。\n");
      if (me->query("family/master_name") !="水母娘娘")
      return notify_fail("你不是水母娘娘的弟子，无法练七夕剑法！ :)\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力修为不够深，七夕剑法学了也没用。\n");
   if (!(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一柄剑才能练习剑法。\n");
   return 1;
}

int practice_skill(object me)
{
   int dod=(int)me->query_skill("dodge");
   int swo=(int)me->query_skill("qixi-sword");

   if (dod<swo/2)
     return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
   if ((int)me->query("kee") < 30)
     return notify_fail("你体力不足，强练七夕剑法有害无益。\n");
   if ((int)me->query("force") < 5)
     return notify_fail("你内力不足，练不了七夕剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   message_vision("$N秀眉轻颦，纤腰微颤，练了一遍七夕剑法。\n", me);
   return 1;
}
 
string *parry_msg = ({
        "$n左掌攻敌，右剑防身，一招「情海无涯」，手中剑狠狠磕开了$N的$w。\n",
        "$n剑出连环，绕住$N的$w，一招「朝朝暮暮」竟使$N难以把持手中的$w。\n",
        "$n使出一招「瑞雪残阳」，手中剑化做漫天雪影残照，荡开了$N的$w。\n",
        "$n使出一招「金风玉露」，亦守亦攻，竟使$N不知是攻是守。\n",
        "$n一招「暮雪三叹」，手中剑急如骤雨般地刺向$N，迫得$N不得不回招自护。\n",
        "$n掌中剑飘忽不定，一招「飞凤青鸾」竟从意想不到的角度架住了$N手中的$w。\n",
        "$n用手中剑带得$N脚步踉跄，一招「自有因缘」封住了$N的攻势。\n",
        "$n使出一招「有情不识」，掌中剑光芒陡长，剑光自远而近，荡开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n使出一招「金风玉露」，亦守亦攻，竟使$N不知是攻是守。\n",
        "$n将剑一抖，使出一招「两情相悦」，剑掌连环，将$N全身团团罩住。\n",   
        "$n将手中剑化做七条剑气，迫得$N连连后退。\n",
        "$n虚晃一剑，身随剑势，在空中盘旋，一招「鹊桥相会」，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int valid_enable(string usage)
{
   return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
   mapping* m_actions;

   if(me->query("skill_qixi")==0) return action[random(sizeof(action))];
   if(random(6)>1) return action[random(sizeof(action))];
   
   m_actions=me->query("skill_qixi");
   return m_actions[random(sizeof(m_actions))];
}

string perform_action_file(string func)
{
return CLASS_D("xuyi") + "/qixi-sword/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("qixi-sword",1);

   if(m_skill>200&&m_skill%20==0){
     tell_object(me,HIY"你对七夕剑法的领悟加深了，你的七夕剑法进入了一个新的境界！\n"NOR);
     if(me->query("qixi/times")>2){
        tell_object(me,HIW"然而你的七夕剑法已经练至顶峰，不能再创出新招了。\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，领悟出了七夕剑法新的用法！\n"NOR);
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

   m_actions=me->query("skill_qixi");
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
   me->set("skill_qixi",m_actions);
   me->add("qixi/times",1);
}

