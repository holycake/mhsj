//Cracked by Roath
inherit NPC;

void create()
{
  set_name("蝙蝠精", ({"bianfu jing","jing"}));
  set("gender", "男性");
  set("age", 40);
  set("long","一个贼眉鼠眼的老妖精。\n");
  set("combat_exp", 300000+random(3000));
  set("daoxing", 300000);

  set("per", 15);
  set_skill("dodge", 130);
  set_skill("parry", 130);
  set_skill("unarmed", 130);
  set_skill("force", 130);
  set_skill("spells", 130);
  set_skill("dagger", 130);

  set("max_sen",800);
  set("max_gee",800);
  set("max_gin",800);

  set("max_force", 500);
  set("force", 500);
  set("force_factor", 25);
  set("max_mana", 500);
  set("mana", 500);
  set("mana_factor", 25);

  setup();
  carry_object("/d/qujing/kusong/obj/needle0")->wield();
  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

