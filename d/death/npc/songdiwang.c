// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
  set_name("宋帝王", ({"songdi wang", "wang", "songdi"}));
  set("title", WHT"阴间十王之"NOR);
  set("gender", "男性");
  set("age", 100);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 5000);
  set("mana_factor", 100);
  set("combat_exp", 1600000);
  set("daoxing", 1500000);

  set_skill("unarmed", 220);
  set_skill("dodge", 220);
  set_skill("parry", 220);
  set_skill("spells", 250);
  set_skill("force", 250);
  set_skill("gouhunshu", 200);
  set_skill("ghost-steps", 200);
  set_skill("jinghun-zhang", 220);
  set_skill("tonsillit", 200);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  
  create_family("阎罗地府", 1, "你好");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}


