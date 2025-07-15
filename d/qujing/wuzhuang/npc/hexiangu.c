// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("何仙姑", ({"he xiangu", "he", "xiangu"}));
	set("title", HIM"八仙之一"NOR);
	set("gender", "女性" );
	set("age", 25);
	set("per", 20);
	set("long", "何仙姑深得镇元大仙喜爱，各位同门大多跟她交好。\n何仙姑原名何秀姑，父亲是开豆腐坊的，她投入五庄观前是当地有名的“豆腐西施”。\n");
	set("class", "xian");
	set("combat_exp", 560000);
  	set("daoxing", 320000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 120);
	set_skill("wuxing-quan", 100);
	set_skill("dodge", 130);
	set_skill("baguazhen", 130);
	set_skill("parry", 110);
	set_skill("sword", 110);
	set_skill("sanqing-jian", 110);
	set_skill("force", 120);   
	set_skill("zhenyuan-force", 120);
	set_skill("literate", 80);
	set_skill("spells", 110);
	set_skill("taiyi", 110);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("dodge", "baguazhen");

	set("max_kee", 700);
	set("max_sen", 700);
	set("force", 2300);
	set("max_force", 1100);
	set("mana", 2300);
	set("max_mana", 1100);	
	set("force_factor", 50);
	set("mana_factor", 50);

	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/heye")->wield();
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
			command("kick " + ob->query("id") );
			command("say 你这个" + RANK_D->query_rude(ob) + "，敢拿姑奶奶我来消遣！\n");
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





