// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 11/20/1997 by snowcat

inherit NPC;
int test_player();
void create()
{
  set_name("����", ({ "zhou wang", "zhou" }));
  set("long", "���ѵ����ǵ����ӹ�޵����������������ô�������³���\n");
  set("gender", "����");
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
    "name" : "�����̳�����Ҳ��������һ��檡�",
    "���" : (: test_player :),
    "槼�" : (: test_player :),
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
    message_vision ("$N��$n˵������ż�����У������˴ʻƣ�\n",me,who);
    message_vision ("\n$N�����ҷԸ��˼��䡣\n",me);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
  //  message_vision ("�������߽����š�\n",who);
    return 1;
  }
  if (who->query("obstacle/xuanyuan")=="done")
  {
    message_vision ("$N��$n˵����Ŷ���㲻���ѹ�����أ������˺θɣ�\n",me,who);
    return 1;
  }
  if (who->query_temp("obstacle/pipa_give"))
  {
//    object junji = present ("jun ji",environment(me));

    message_vision ("$N��$n˵���������ͿҲ������������檣�\n",me,who);
 //   if (! junji)
 //   {
 //     message_vision ("\n$N��ֵ��������󳼺��ڣ�\n",me);
 //     return 1;
 //   }
 //   message_vision ("\n$N��$n�Ը��˼��䡣\n",me,junji);
    remove_call_out ("following");
    call_out ("following",5,me,who);
    return 1;
  }
//  message_vision ("$N��$n˵��������β��󹬰ݼ�������\n",me,who);
//  return 1;
}

void following (object me, object who)
{
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

//  message_vision ("\n$N���˵�ͷ��\n",junji);
  message_vision ("$N��$n˵�����ɷ������ȥѰ����������ˣ�\n",who);
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
  command("chat "+who->query("name")+"��ԯĹ������������");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}




