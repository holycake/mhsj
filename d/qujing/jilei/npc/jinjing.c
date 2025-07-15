//Cracked by Roath

inherit NPC;

void create()
{
  set_name("避水金睛兽", ({"jinjing shou", "shou"}));
  set("under_water",1);

  set("long", "一头双眸放光，银掌玉鞍的金睛兽，上天入海，如履平地。\n");
  set("race", "野兽");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "骑");
  set("ride/dodge", 35);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}


