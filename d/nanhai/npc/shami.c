//Cracked by Roath
// shami.c 小沙弥
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("小沙弥", ({ "shami", "bonze" }));
	set("gender", "男性");
	set("age", 10);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 100);
	set("max_gin", 100);
	set("max_sen", 100);
	set("combat_exp", 1000);
	set_skill("literate", 20);
	set_skill("unarmed", 20);
	set_skill("dodge", 25);
	set_skill("parry", 20);
	set_skill("force", 10);
	
	setup();
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

