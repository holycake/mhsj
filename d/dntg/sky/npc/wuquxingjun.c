//sgzl

inherit NPC;

void create()
{
  set_name("武曲星君",({"wuqu xingjun","xingjun"}));
  set("gender", "男性");
  set("age", 40);
  set("long", "    \n天宫的武曲星君。\n");

  set("attitude", "peaceful");
  set("class", "xian");
  set("combat_exp", 600000);
  set("daoxing", 800000);
  set("kee", 1400);
  set("max_kee", 1400);
  set("sen", 1600);
  set("max_sen", 1600);
  set("force", 1500);
  set("max_force", 1500);
  set("mana", 1600);
  set("max_mana", 1600);
  set("force_factor", 50);
  set("mana_factor", 40);
  set("str", 25);
  set("kar", 25);


  set_skill("literate", 70);
  set_skill("parry", 100);
  set_skill("unarmed", 100);
  set_skill("sword", 100);
  set_skill("spells", 100);
  set_skill("force", 100);
  set_skill("xiaofeng-sword", 100);


map_skill("sword", "xiaofeng-sword");
  set("inquiry", ([
  "name"   : "武曲星君。",
]));


setup();

carry_object("/d/obj/cloth/xianpao")->wear();

}
