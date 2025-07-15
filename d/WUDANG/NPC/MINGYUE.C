
// mingyue.c

inherit NPC;

void create()
{
	set_name("明月", ({ "ming yue", "ming", "yue" }));
	set("long", 
		"他是武当山的小道童。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");

	set("str", 20);

	set("combat_exp", 5000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("武当派", 4, "弟子");

	setup();
	
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
