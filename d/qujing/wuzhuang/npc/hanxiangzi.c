// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("韩湘子", ({"han xiangzi", "han", "xiangzi"}));
	set("title", WHT"八仙之一"NOR);
	set("gender", "男性" );
	set("age", 22);
	set("per", 30);
	set("food", 1000);
	set("water", 1000);
	set("long", "好一位俊雅潇洒的相公。韩湘子本是名门之后，却不喜念书入仕。\n被其族中长者以轻狂不学斥出家门。\n");
	set("class", "xian");
	set("combat_exp", 620000);
  set("daoxing", 300000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 90);
	set_skill("wuxing-quan", 90);
	set_skill("dodge", 100);
	set_skill("baguazhen", 100);
	set_skill("parry", 100);
	set_skill("sword", 110);
	set_skill("xiaofeng-sword", 110);
	set_skill("force", 110);   
	set_skill("zhenyuan-force", 110);
	set_skill("literate", 150);
	set_skill("spells", 100);
	set_skill("taiyi", 100);
	set_skill("zouxiao", 200);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "xiaofeng-sword");
	map_skill("dodge", "baguazhen");

	set("max_kee", 700);
	set("max_sen", 700);
	set("force", 2000);
	set("max_force", 1200);
	set("mana", 2000);
	set("max_mana", 1200);	
	set("force_factor", 50);
	set("mana_factor", 50);

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/weapon/sword/zijinxiao")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="五庄观" )
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
			command("consider");
			command("say 是你自己要拜的，你师父打上门来我可得拿你挡。\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say 好，我五庄观一门人才辈出，你可得给师父争气。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}





