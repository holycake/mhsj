//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

string *names = ({
  "长舌妖",
  "三腿妖",
  "扫把妖",
  "断头妖",
});

void create()
{
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("race", "野兽");
  set("age", 100+random(201));
  set("combat_exp", 500000+random(500001));
  set("daoxing", 500000+random(500001));
  set("limbs", ({ "头部", "身体", "前爪", "尾巴", "肚皮", "后爪"}) );
  set("verbs", ({ "bite", "claw"}) );
  set("attitude", "aggressive");
  set("per", 10);
  set_skill("parry", 200);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("blade", 200);
  set("max_sen",2000);
  set("max_kee",2000);
  set("force",2000);
  set("max_force",1500);
  set("max_mana",1500);
  set("mana",2000);
  set("mana_factor",50);
  set("force_factor",50);
   add_temp("apply/damage", 50);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jilei/obj/armor")->wear();
}
