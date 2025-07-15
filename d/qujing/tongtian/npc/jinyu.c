// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("金鳞怪", ({ "jinlin guai", "jinglin", "guai" }));
  set("title", YEL"通天河"NOR);   
  set("long", "一位身着金甲的妖怪。\n");
  set("gender", "男性");
  set("age", 76);
  set("attitude", "aggressive");
  set("per", 30);
  set("max_kee", 4000);
  set("max_gin", 4000);
  set("max_sen", 4000);
  set("force", 7000);
  set("max_force", 3500);
  set("force_factor", 160);
  set("max_mana", 3500);
  set("mana", 7000);
  set("mana_factor", 160);
  set("combat_exp", 5000000);
  set("daoxing", 2000000);

  set_skill("spells", 430);
  set_skill("dao", 430);
  set_skill("unarmed", 385);
  set_skill("hammer", 385);
  set_skill("dragonfight", 385);
  set_skill("dodge", 380);
  set_skill("dragonstep", 370);
  set_skill("parry", 385);
  set_skill("force", 370);
  set_skill("dragonforce", 420);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragon-step");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/hammer/bahammer")->wield();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
    ob->set_temp("obstacle/tongtian_killed",1);
    call_out ("chen_appearing",1,ob);
  }
  message_vision ("\n$N一甩尾巴，现出金鱼的原身。\n",me);
  message_vision ("\n天上怒喝一声：金鱼，归我莲花池也！\n",me);
  message_vision ("金鱼闻声，乖乖地一纵身扭着腰摇晃着头游走了。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void chen_appearing (object who)
{
  object chen = new ("/d/qujing/tongtian/npc/chen");

  chen->announce_success (who);
  destruct (chen); 
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

