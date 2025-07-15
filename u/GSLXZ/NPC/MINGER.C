// minger.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("明儿", ({"ming er", "er", "minger"}));
	//set("title", "");
	set("gender", "女性" );
	set("age", 22);
	set("per", 30);
	set("long", "蜀山派的第三代弟子。\n");
	set("class", "xiake");
	set("combat_exp", 120000);
       set("daoxing", 200000);
       set("attitude", "peaceful");
	create_family("蜀山", 3, "弟子");
	set_skill("dodge", 90);
	set_skill("zuixian-steps", 90);
	set_skill("parry", 70);
	set_skill("whip", 80);
	set_skill("snowwhip", 80);
	set_skill("force", 70);   
	set_skill("shushan-force", 80);
	set_skill("literate", 120);
	set_skill("spells", 80);
	set_skill("xianfeng-spells", 80);
	map_skill("spells", "xianfeng-spells");
	map_skill("force", "shushan-force");
	map_skill("whip", "snowwhip");
	map_skill("dodge", "zuixian-steps");
       set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/whip/whip")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="蜀山" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("blush");
			command("say 你比松儿好!\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say 好，我蜀山派一门人才辈出，你可得给师父争气。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xiake");
}




