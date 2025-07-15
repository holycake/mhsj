// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
//justin made 
// created 11/20/1997 by snowcat

inherit NPC;
#include <ansi.h>
int test_player();
void create()
{
  set_name("纣王", ({ "zhou wang", "zhou" }));
  set("long", "这难道就是当年昏庸无道的纣王？他如今怎么落的如此下场？\n");
  set("gender", "男性");
  set("age", 47);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 700);
  set("max_force", 700);
  set("force_factor", 60);
  set("max_mana", 700);
  set("mana", 400);
  set("mana_factor", 60);
  set("combat_exp", 410000);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jienan-zhi", 50);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  set("inquiry", ([
    "name" : "朕乃商朝国君也，寡人有一爱妾。",
    "爱妾" : (: test_player :),
    "妲几" : (: test_player :),
    "妲己" : (: test_player :),

  ]));

  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
}
int test_player ()
{
  object me = this_object();
  object who = this_player();

  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N对$n说道：你才几年道行，就来此词黄？\n",me,who);
    message_vision ("\n$N对左右吩咐了几句。\n",me);
    who->move("/d/city/center");
   // who->move("/d/qujing/tianzhu/wumen");
  //  message_vision ("伺卫官走进午门。\n",who);
    return 1;
  }
  if (who->query("obstacle/xuanyuan")=="done")
  {
    command("fear");
    command("sigh");
    return 1;
  }
  if (who->query_temp("can_in"))
  {
//    object junji = present ("jun ji",environment(me));

    message_vision (CYN"$N对$n说道：我真对不起我们成汤的江山呀，误将妖精当爱妾！\n"NOR,me,who);
 //   if (! junji)
 //   {
 //     message_vision ("\n$N奇怪道：军机大臣何在？\n",me);
 //     return 1;
 //   }
 //   message_vision ("\n$N对$n吩咐了几句。\n",me,junji);
    remove_call_out ("following");
    call_out ("following",2,me,who);
    return 1;
  }
//  message_vision ("$N对$n说道：驸马何不后宫拜见公主？\n",me,who);
//  return 1;
}

void following (object me,object who)

 {
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

  message_vision ("纣王说道：可否带我去寻她这个负心人？\n",who);
command("sigh");
  message_vision ("$N决定开始跟随$n一起行动。\n",me,who);
  me->set_leader(who);
  who->set("mysaver",who);
  if (taijian1)
  message_vision ("$N决定开始跟随$n一起行动。\n",taijian1,who);
     taijian1->set_leader(who);
  if (taijian2)
  message_vision ("$N决定开始跟随$n一起行动。\n",taijian2,who);
     taijian2->set_leader(who);
}




