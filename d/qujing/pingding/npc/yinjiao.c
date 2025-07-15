// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"银角大王"NOR, ({ "yinjiao dawang", "yinjiao", "dawang", "wang" }));
  set("title", WHT"莲花洞"NOR);   
  set("long", "一位神态傲然的莲花洞妖王。\n");
  set("gender", "男性");
  set("age", 54);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 3800);
  set("max_gin", 3800);
  set("max_sen", 3800);
  set("force", 7000);
  set("max_force", 3500);
  set("force_factor", 180);
  set("max_mana", 3500);
  set("mana", 7000);
  set("mana_factor", 180);
  set("combat_exp", 3950000);
  set("daoxing", 1600000);

  set_skill("spells", 290);
  set_skill("dao", 290);
  set_skill("unarmed", 295);
  set_skill("puti-zhi", 295);
  set_skill("dodge", 280);
  set_skill("jindouyun", 280);
  set_skill("parry", 295);
  set_skill("force", 290);
  set_skill("wuxiangforce", 290);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
  if ("/d/qujing/pingding/obj/pingreal"->in_mud())
    carry_object("/d/qujing/pingding/obj/pingfake");
  else
    carry_object("/d/qujing/pingding/obj/pingreal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);

  if (ob)
  {
    ob->set_temp("obstacle/pingding_yinjiao_killed",1);
    call_out ("taishang_appearing",1,ob);
  }
  message_vision ("\n$N无可奈何地现了真身，原来是太上老君的银角童子。\n",me);
  message_vision ("\n银角童子鞠了个躬：时辰已到，去见太上老君也。\n",me);
  message_vision ("银角童子往外奔去",me);
  if (fabao)
  {
    message_vision ("，丢下一只$n。\n",me,fabao);
    fabao->move(environment(me));
  }
  else
    message_vision ("。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void taishang_appearing (object who)
{
  object taishang = new ("/d/qujing/pingding/npc/taishang");

  taishang->announce_success (who);
  destruct (taishang); 
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

