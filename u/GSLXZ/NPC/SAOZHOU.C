#include <ansi.h>

  inherit "/d/sea/npc/beast/beast.c";

void create()
{
    set_name("扫帚", ({"sao zhou" , "sao"}));
  set("race", "野兽");
  set("age", 20);
    set("long", "一头凶猛的野兽被雨点变成了一把大扫帚。\n");
  set("daoxing", 150000);

  set("combat_exp", 150000);
  set("limbs", ({ "头部", "身体", "腿部", "翅膀", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("max_kee", 800);
  set("kee", 800);
  set("max_sen", 900);
  set("sen", 900);

  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("unarmed", 150);
  set("female_only", 1);
  set("ride/need_train", 1);
    set("ride/msg", "骑");
  set("ride/dodge", 25);
  set("bird", 1);
      set_temp("apply/dodge", 50);
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

