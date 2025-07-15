// by gslxz@mhsj 2001/11/21 (优化)
inherit NPC;
#include <ansi.h>

void create()
{
    set_name("翠兰", ({ "cui lan","lan" }));
  set("age", 20);
  set("title", HIM"高老庄三小姐"NOR);
    set("gender", "女性");
  set("long", "她就是高老庄的三小姐。\n");
  set("attitude", "peaceful");
       set("class", "xian");
  set("str", 50);
  set("per", 30);
  set("combat_exp", 3800000);
  set("daoxing", 2570000);

  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_mana", 3000);
  set("mana", 6000);
  set("max_force", 3000);
  set("force", 6000);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 450);
  set_skill("dodge", 450);
  set_skill("parry", 430);
  set_skill("rake", 450);
  set_skill("force", 450);
  set_skill("spells", 450);
  set_skill("xbuddhism", 470);
    set_skill("tianpeng-force", 470);
  set_skill("literate", 400);
  set_skill("yanxing-steps", 430);
  set_skill("skyriver-rake", 450);
  set_skill("sougu-zhua", 430);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("天蓬府", 2, "弟子");
  setup();
    carry_object("/d/tianpeng/obj/yupa")->wield();
  carry_object("/d/tianpeng/obj/pink")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 1000000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
	return;
	}

	if ( (string)ob->query("family/family_name")=="天蓬府") {
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们天蓬府发扬光大。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
                ob->set("class", "xian");
                ob->set("per",11);
}




