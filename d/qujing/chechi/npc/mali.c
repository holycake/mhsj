// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  string dir;

  set_name("犸力大仙", ({"mali daxian", "daxian"}));
  set("gender", "男性");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 4700000+random(50000));
  set("daoxing", 3000000);

  set_skill("dodge", 370);
  set_skill("parry", 370);
  set_skill("force", 370);
  set_skill("spells", 370);
  set_skill("unarmed", 370);
  set_skill("gouhunshu", 350);
  set_skill("tonsillit", 350);
  set_skill("ghost-steps", 330);
  set_skill("jienan-zhi", 340);
  set("con", 70);
  set("cor", 70);
  set("int", 70);
  set("per", 70);
  set("spi", 70);
  set("cps", 70);
  //map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-300000);
  set("nkgain",400);

  set("max_gin", 3200);
  set("max_kee", 3200);
  set("max_sen", 3200);
  set("force", 3200);
  set("max_force", 3200);
  set("mana", 3200);
  set("max_mana", 3200);
  set("force_factor", 15);
  set("mana_factor", 80);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void unconcious()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N浑身一软瘫在地上，化做一堆零散的兽骨。\n",
                  this_object());
  destruct(this_object());
}

void die()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N浑身一软瘫在地上，化做一堆零散的兽骨。\n",
                  this_object());
  destruct(this_object());
}

