// honghaier.c 小红孩儿
// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("小红孩儿", ({ "honghaier" }));
 set("title", WHT"南海观音之徒"NOR); 
	set("long", @LONG
他本是牛魔王之子，生性好斗；后被南海观音收服，脾气却不见有什么好转。
他使得一手的好枪法，火云枪更是鲜有敌手，寻常人是不敢碰他的。
LONG);
	set("gender", "男性");
	set("age", 15);
	set("food", 1000);
	set("water", 1000);
	set("attitude", "heroism");
          set("max_kee", 2000);
           set("max_gin", 2000);
           set("max_sen", 2000);
           set("force", 3500);
          set("max_force", 3500);
           set("force_factor", 150);
          set("max_mana", 3500);
          set("mana", 3500);
          set("mana_factor", 150);
          set("combat_exp", 2400000);
          set("daoxing", 2300000);

set_skill("literate", 280);
  set_skill("spells", 270);
          set_skill("buddhism", 280);
 set_skill("unarmed", 260);
 set_skill("jienan-zhi", 260);
set_skill("dodge", 280);
set_skill("lotusmove", 280);
 set_skill("parry", 280);
 set_skill("force", 275);
 set_skill("lotusforce", 270);
          set_skill("staff", 250);
          set_skill("lunhui-zhang", 240);
          set_skill("spear", 230);
          set_skill("huoyun-qiang", 250);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "huoyun-qiang");
	map_skill("staff", "lunhui-zhang");
	map_skill("spear", "huoyun-qiang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :),
	}) );

	create_family("南海普陀山", 2, "弟子");

	setup();
	carry_object("/obj/money/gold");
	carry_object("/obj/money/gold");
	carry_object("/obj/cloth")->wear();
	carry_object("/d/nanhai/obj/jingu2");
	carry_object("/d/nanhai/obj/huojianqiang")->wield();
}

void attempt_apprentice(object ob)
{
	if (((int)ob->query_skill("buddhism", 1) < 200 )) {
		command("say " + RANK_D->query_respect(ob) + "的佛法修行还不精，还需多加努力才是！");
		return;
	}
	command("smile");
	command("say 很好，我就收下你，希望你多加努力，早成正果。\n");

	command("recruit " + ob->query("id") );
	return;
}


