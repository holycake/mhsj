// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("快如风", ({"kuairu feng","feng"}));
  set("gender", "男性");
  set("age", 10);
  set("title", RED"火云洞健将"NOR);
  set("long","一个贼眉鼠眼的小妖精。\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);

  set("per", 15);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("unarmed", 160);
  set_skill("force", 160);
  set_skill("spells", 160);
  set("max_sen",800);
  set("max_gee",800);
  set("max_gin",800);

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

