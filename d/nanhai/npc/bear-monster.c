// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黑熊怪", ({ "bear monster", "bear", "monster" }));
	set("title", WHT"南海观音之徒"NOR);   
	set("long", @LONG
黑熊怪本是山间野兽，不知从哪里学到一身好本领。
后遇见南海观音，被南海观音收为徒弟。
LONG);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroism");
	set("per", 9);
	set("rank_info/self", "黑熊");
	set("rank_info/rude", "熊怪");
	set("max_kee", 850);
	set("max_gin", 800);
	set("max_sen", 850);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("max_mana", 800);
	set("mana", 1600);
	set("mana_factor", 30);
	set("combat_exp", 500000);
	set("daoxing", 300000);
	set("food", 1000);
	set("water", 1000);

	set_skill("literate", 50);
	set_skill("spells", 120);
	set_skill("buddhism", 120);
	set_skill("unarmed", 100);
	set_skill("jienan-zhi", 100);
	set_skill("dodge", 90);
	set_skill("lotusmove", 90);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("lotusforce", 100);
	set_skill("staff", 110);
	set_skill("lunhui-zhang", 110);
//	set_skill("spear", 60);
//	set_skill("huoyun-qiang", 50);

	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	map_skill("spear", "huoyun-qiang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :),
	}) );
        create_family("南海普陀山", 2, "弟子");

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/d/nanhai/obj/jingu3");
//	carry_object("/d/nanhai/obj/jingu3");
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="南海普陀山") {
		command("smile");
		command("say 很好，我就收下你，希望你多加努力，早成正果。\n");

		command("recruit " + ob->query("id") );
		return;
	}

	command("shake");
	command("say " + "菩萨不让我随便收外人为徒。\n");
	return;
}


