// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 11/20/1997 by snowcat

inherit NPC;
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
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
  //  message_vision ("伺卫官走进午门。\n",who);
    return 1;
  }
  if (who->query("obstacle/xuanyuan")=="done")
  {
    message_vision ("$N对$n说道：哦，你不是已过了这关，有来此何干？\n",me,who);
    return 1;
  }
  if (who->query_temp("obstacle/pipa_give"))
  {
//    object junji = present ("jun ji",environment(me));

    message_vision ("$N对$n说道：朕真糊涂也，误将妖精当爱妾！\n",me,who);
 //   if (! junji)
 //   {
 //     message_vision ("\n$N奇怪道：军机大臣何在？\n",me);
 //     return 1;
 //   }
 //   message_vision ("\n$N对$n吩咐了几句。\n",me,junji);
    remove_call_out ("following");
    call_out ("following",5,me,who);
    return 1;
  }
//  message_vision ("$N对$n说道：驸马何不后宫拜见公主？\n",me,who);
//  return 1;
}

void following (object me, object who)
{
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

//  message_vision ("\n$N点了点头。\n",junji);
  message_vision ("$N对$n说道：可否带陛下去寻她这个负心人？\n",who);
 // junji->command_function ("follow "+who->query("id"));
  me->command_function ("follow "+who->query("id"));
  me->set("my_saver",who);
  if (taijian1)
    taijian1->command_function ("follow "+who->query("id"));
  if (taijian2)
    taijian2->command_function ("follow "+who->query("id"));
}
void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/xuanyuan") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/xuanyuan","done");
  who->add("combat_exp",i+8000);
  command("chat "+who->query("name")+"轩辕墓救朕脱牢笼！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}




