// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("老奶奶", ({ "lao nainai", "lao", "nainai", "queen" }));
  set("title", YEL"压龙洞"NOR);   
  set("long", "一位扭腰摆臀的压龙洞妖后，身上隐隐地发出狐臭。\n");
  set("gender", "女性");
  set("age", 86);
  set("attitude", "heroism");
  set("per", 12);
  set("max_kee", 2800);
  set("max_gin", 2800);
  set("max_sen", 2800);
  set("force", 7000);
  set("max_force", 3500);
  set("force_factor", 140);
  set("max_mana", 3500);
  set("mana", 7000);
  set("mana_factor", 140);
  set("combat_exp", 3750000);
  set("daoxing", 1600000);

  set_skill("spells", 250);
  set_skill("dao", 250);
  set_skill("unarmed", 255);
  set_skill("puti-zhi", 255);
  set_skill("dodge", 250);
  set_skill("jindouyun", 250);
  set_skill("parry", 255);
  set_skill("force", 250);
  set_skill("wuxiangforce", 250);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/pingding_laonai_killed",1);
    call_out ("taishang_appearing",1,ob);
  }
  message_vision ("\n$N翻倒在地现了真身，是一只狐狸精。\n",me);
  message_vision ("狐狸精死了。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
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
  ::kill_ob(ob);
}


