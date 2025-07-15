// daotong.c 道童

inherit NPC;

void create()
{
	set_name("道童", ({ "daotong", "dao", "tong" }));
	set("long", 
		"他是武当山的小道童。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");

	set("str", 20);
	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("武当派", 4, "弟子");

	setup();
	
//          carry_object("/d/wudang/obj/greyrobe")->wear();

}
