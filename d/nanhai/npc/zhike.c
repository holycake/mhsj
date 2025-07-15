//Cracked by Roath
// zhike.c 知客僧?
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("知客僧", ({ "zhike seng", "seng" }));
	set("long", "一位年轻的僧人，脸上总是带着热情的笑容。\n他负责在此迎接前来参禅进香的客人。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);

	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

        create_family("南海普陀山", 4, "弟子");
	
	setup();
	add_money("silver", 20);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
	&& !ob->query("env/invisibility") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "知客僧热情地说道：这位" + RANK_D->query_respect(ob) + "，欢迎来到南海普陀山！\n");
}


