// by snowcat 

inherit NPC;

#include <quest_ak.c>
#include <reporting.c>

string *strs = ({
    "$N燃起一根香祭祀一番，对$n说道：祖灵在天，请您去拜见$w并询问有关$o一事。\n",
    "$N将手中香点燃对$n说道：老夫祭毕祖宗，得知有$w知道$o之事，您可否去请见？\n",
    "$N拈香向祖宗一拜，转身对$n说道：可否去拜见$w，并告知$o一事？\n",
    "$N将香点燃，对$n说道：在天祖灵让您就$o一事拜访$w，请尽早动身也。\n",
    "$N对$n说道：老夫拜了祖宗，正缺人去拜访$w，告知$o之事。\n",
    "$N燃香完毕，回头对$n说道：不知可否去拜见$w，探问$o一事。\n",
    "$N在香火中缓缓向祖宗一拜，再对$n说道：祖灵在天请您去拜见$w并告知$o之事。\n",
  });  

// mon 3/22/99
string get_message(string str1, string str2)
{
    string str;
    string *msg1=({"$N燃起一根香祭祀一番，对$n说道：祖灵在天，请您去"});
    string *msg2=({"拜见","朝问","问候","拜访","求见","看望","访问","致意",
	    "问候一下","拜访一次","拜见一次","问候一回","看望一下","求见一次",
	    "访问一次","访问一回","拜访一回","致意一次","拜访一下","看望一下",
	    "拜见拜见","问候问候","拜访拜访","看望看望"});
    string *msg3=({"，顺路","，并","，并且","，一定","，尽力",
	    "并","并且",});
    string *msg4=({"探听","索问","请问","打听","探问","查询","探知","寻查",
	           "探访","调查","查知","探访","调查","过问","打探","查明",
	    "探访探访","寻查寻查","打探打探","务必探明","一定探知","调查调查",
	    "探听有关","打探有关","打听有关","查询有关","探知有关","探问有关",
            "探听关于","打探关于","打听关于","查询关于","探知关于","探问关于",
	    "查问有关","查问关于","调查有关","调查关于","请问有关","请问关于",
	    "探听探听","打听打听","探问探问","查明有关","过问有关"});
    string *msg5=({"一事","之事","的消息","的情况","的问题",});
    string *msg6=({"！","。","。。。",});
    
    if(random(10)<3)
      str = strs[random(sizeof(strs))];
    else {
	str=msg1[random(sizeof(msg1))]+
	    msg2[random(sizeof(msg2))]+"$w"+
	    msg3[random(sizeof(msg3))]+
	    msg4[random(sizeof(msg4))]+"$o"+
	    msg5[random(sizeof(msg5))]+
	    msg6[random(sizeof(msg6))]+"\n";
    }
    str = replace_string (str, "$w", str1);
    str = replace_string (str, "$o", str2);
    return str;
}

void show_message(object who)
{
    string str;

    if(!who) return;
    if (! who->query("quest/pending/ask"))
	return;
    str=who->query("quest/pending/ask/message");
    if(!str) 
      message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是请您去见"+who->query("quest/pending/ask/name")+
                    "询问"+who->query("quest/pending/ask/topic")+"一事吗？\n",
		    this_object(),who);
    else
      message_vision(str,this_object(),who);
}

int test_player();

void create()
{
  set_name("陈光蕊", ({"chen guangrui", "chen", "guangrui"}));
  set("long", "陈光蕊乃玄奘之父，当朝大阐都纲御赐状元。\n");
  set("title", "大阐都纲");
  set("gender", "男性");
  set("age", 50);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "scholar");
  set("shen_type", 1);
  set("combat_exp", 40000);
  set("daoxing", 100000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("literate", 180);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "光蕊大师说道：善哉善哉哪。\n",
    "光蕊大师自语道：世上贤人，有求必应哪。\n",
    "光蕊大师说道：祭祖求贤，乃水陆大会前之必需也。\n",
    "光蕊大师叹言道：天下招贤，利国利民之大策也。\n",
    "光蕊大师说道：八方求贤也。\n",
    "光蕊大师说道：焚香祭祖，以招天下招贤士。\n",
  }));
  set("inquiry", ([
        "here":   "此乃禹王台也，水陆大会将不期举行，本状元在此预做法场以祭祖求贤。\n",
        "name":   "玄奘之父陈光蕊也，在此做法祭祖求贤。\n",
        "ask":   (: test_player() :),
        "祭祖":   (: test_player() :),
        "求贤":   (: test_player() :),
        "招贤":   (: test_player() :),
        "贤人":   (: test_player() :),
        "贤士":   (: test_player() :),
        "善哉":   (: test_player() :),
        "招":   (: test_player() :),
        "求":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *acks = ({
    "知道了。\n",
    "我这就会动身，您请先回吧。\n",
    "好的。\n",
    "多谢来访，我这就去办。\n",
    "好，我马上就去准备。\n",
  });
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  string str;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/ask"))
  {
      call_out("show_message",1,who);

//    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
//                    "，老夫不是请您去见"+who->query("quest/pending/ask/name")+
//                    "询问"+who->query("quest/pending/ask/topic")+"一事吗？\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_ask);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/ask");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，老夫看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_ask[quest_keys[i]];
  who->set("quest/pending/ask/index", i);
  who->set("quest/pending/ask/daoxing", quest_keys[i]);
  who->set("quest/pending/ask/name", quest[IDX_NAME]);
  who->set("quest/pending/ask/id", quest[IDX_ID]);
  who->set("quest/pending/ask/topic", quest[IDX_OBJ]);
  who->set("quest/pending/ask/acknowledge", acks[random(sizeof(acks))]);
  who->set("quest/pending/ask/time", delay);
  
  str=get_message(quest[IDX_NAME], quest[IDX_OBJ]);
  who->set("quest/pending/ask/message",str);

//  str = strs[random(sizeof(strs))];
//  str = replace_string (str, "$w", quest[IDX_NAME]);
//  str = replace_string (str, "$o", quest[IDX_OBJ]);
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  int t;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

  if (! who->query("quest/pending/ask"))
    return;

  if (! who->query("quest/pending/ask/done"))
  {
      call_out("show_message",1,who);
//    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
//                    "，老夫不是说过请去拜见"+who->query("quest/pending/ask/name")+
//                    "并告之"+who->query("quest/pending/ask/topic")+"一事吗？\n",me,who);
    return;
  }

  t = who->query("quest/pending/ask/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n惊叹道：您已经回来了？不会这么快吧。\n",me,who);
    message_vision ("$N看了一眼香说道：这香还需"+chinese_number((t-uptime())/60+1)+
                    "分钟才燃尽，到时您再来吧。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让陈光蕊直接认可。\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "祭祖拜贤，就"+who->query("quest/pending/ask/topic")+
           "一事拜见了"+who->query("quest/pending/ask/name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"真是品行可嘉也。\n",me,who);
  reward = quest_reward(who, quests_ask, "ask");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/ask/times",1);
  who->add("quest/ask/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/ask");
  quest_done(who);
}

