// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("曹国舅", ({"cao guojiu", "cao", "guojiu"}));
	//set("title", "");
	set("gender", "男性" );
	set("age", 40);
	set("per", 20);
	set("title", WHT"八仙之一"NOR);
	set("long", "一位神情严肃的中年人。曹国舅名景休，天资纯善，\n不喜富贵，酷慕清虚。其弟骄纵不法，后罔逃国宪。\n曹国舅深以为耻，遂隐迹山林，精思元理。后投入镇元门下。\n");
	set("class", "xian");
	set("combat_exp", 720000);
           set("daoxing", 500000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 110);
	set_skill("wuxing-quan", 120);
	set_skill("dodge", 100);
	set_skill("baguazhen", 100);
	set_skill("parry", 120);
	set_skill("hammer", 100);
	set_skill("kaishan-chui", 100);
	set_skill("force", 120);   
	set_skill("zhenyuan-force", 120);
	set_skill("literate", 90);
	set_skill("spells", 100);
	set_skill("taiyi", 100);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("hammer", "kaishan-chui");
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
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/hammer/baiyuban")->wield();
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
		command("say 好，不过在我这儿可不许偷懒！\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}




