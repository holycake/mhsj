// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
  set_name("秦广王", ({"qinguang wang", "wang", "qinguang"}));
  set("title", WHT"阴间十王之"NOR);
  set("gender", "男性");
  set("age", 60);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 100);
  set("combat_exp", 1800000);
  set("daoxing", 1700000);

  set_skill("unarmed", 240);
  set_skill("jinghun-zhang", 220);
  set_skill("dodge", 240);
  set_skill("parry", 240);
  set_skill("gouhunshu", 200);
  set_skill("tonsillit", 200);
  set_skill("spells", 220);
  set_skill("force", 220);
  set_skill("ghost-steps", 200);
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  create_family("阎罗地府", 2, "你好");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  //        carry_object("/d/lingtai/obj/shoe")->wear();
  //        carry_object("/d/lingtai/obj/putibang")->wield();
}
void attempt_apprentice(object ob, object me)
{
  if (((int)ob->query("combat_exp") < 250000 )) {
    command("say " + RANK_D->query_rude(ob) + "功底如此之差，不配做我徒弟！");
    return;
  }
  command("haha");
  command("say 很好，" + RANK_D->query_respect(ob) +
	  "多加努力，他日必定有成。\n");
  command("recruit " + ob->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "youling");
}


