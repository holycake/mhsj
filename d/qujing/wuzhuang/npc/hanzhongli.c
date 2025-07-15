// by gslxz@mhsj 2001/10/24
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("汉钟离", ({"han zhongli", "han", "zhongli"}));
	set("title", WHT"八仙之一"NOR);
	set("gender", "男性" );
	set("age", 50);
	set("per", 20);
	set("long", "一位大腹便便的胖老头。大概总是觉得太热，时不时地要扇几扇。\n据说他以前喜欢带兵打仗，却又实在不是当将军的料，每每大败而回。\n心灰意冷之下便出门学道访仙，后拜在了镇元门下。\n");
	set("class", "xian");
	set("combat_exp", 720000);
          set("daoxing", 600000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 120);
	set_skill("wuxing-quan", 120);
	set_skill("dodge", 110);
	set_skill("baguazhen", 100);
	set_skill("parry", 120);
	set_skill("blade", 120);
	set_skill("yange-blade", 110);
	set_skill("force", 120);   
	set_skill("zhenyuan-force", 120);
	set_skill("literate", 90);
	set_skill("spells", 110);
	set_skill("taiyi", 110);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("blade", "yange-blade");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 2600);
	set("max_force", 1300);
	set("mana", 2600);
	set("max_mana", 1300);	
	set("force_factor", 50);
	set("mana_factor", 50);

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/blade/bajiaoshan")->wield();
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




