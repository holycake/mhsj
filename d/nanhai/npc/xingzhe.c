// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("游方行者", ({ "xingzhe" }));
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("class", "bonze");
       	set("food", 1000);
	set("water", 1000);
	set("max_kee", 550);
	set("max_gin", 500);
	set("max_sen", 550);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 35);
	set("max_mana", 1000);
	set("mana", 2000);
	set("mana_factor", 30);
	set("combat_exp", 700000);
	set("daoxing", 500000);


        set("eff_dx", 40000);
        set("nkgain", 250);

	set_skill("literate", 100);
	set_skill("spells", 100);
	set_skill("buddhism", 100);
	set_skill("unarmed", 100);
	set_skill("jienan-zhi", 110);
	set_skill("dodge", 100);
	set_skill("lotusmove", 100);
	set_skill("parry", 90);
	set_skill("force", 100);
	set_skill("lotusforce", 120);
	set_skill("staff", 120);
	set_skill("lunhui-zhang", 110);
//	set_skill("spear", 50);
//	set_skill("huoyun-qiang", 50);
	map_skill("spear", "huoyun-qiang");
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

        create_family("南海普陀山", 3, "弟子");
	
	setup();
	carry_object("/obj/money/gold");
	carry_object("/d/nanhai/obj/sengpao")->wear();
	carry_object("/d/nanhai/obj/tiezhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("smile");
	command("say 很好，贫僧就收下你，希望你多加努力，早成正果。\n");

	command("recruit " + ob->query("id") );
	return;
}


