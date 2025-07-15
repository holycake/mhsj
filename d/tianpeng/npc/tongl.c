// by gslxz@mhsj 2001/11/21 (优化)
inherit NPC;
#include <ansi.h>

void create()
{
  set_name("猪大常", ({ "zhu dachang", "zhu", "dachang" }));
  set("age", 600);
  set("title", HIY"天蓬府护院统领"NOR);
    set("gender", "男性");
  set("long", "他就是天蓬府的护院统领。\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 15);
  set("combat_exp", 2000000);
  set("daoxing", 1900000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_mana", 2700);
  set("mana", 3700);
  set("max_force", 2700);
  set("force", 3700);
  set("force_factor", 90);
  set("mana_factor", 90);
  set_skill("rake", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 210);
  set_skill("spells", 200);
  set_skill("xbuddhism", 205);
    set_skill("tianpeng-force", 205);
  set_skill("yanxing-steps", 200);
  set_skill("skyriver-rake", 205);
  map_skill("rake", "skyriver-rake");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("天蓬府", 3, "弟子");
  setup();
  carry_object("/d/tianpeng/obj/jinjia")->wear();
  carry_object("/d/tianpeng/obj/gangpa")->wield();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 500000 )) {
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




