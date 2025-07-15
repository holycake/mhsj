// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("蓝采和", ({"lan caihe", "lan", "caihe"}));
	set("title", WHT"八仙之一"NOR);
	set("gender", "男性" );
	set("age", 18);
	set("per", 20);
	set("long", "一位面腆和善的少年。\n");
	set("class", "xian");
	set("combat_exp", 670000);
          set("daoxing", 360000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 100);
	set_skill("wuxing-quan", 100);
	set_skill("dodge", 100);
	set_skill("baguazhen", 90);
	set_skill("parry", 90);
	set_skill("blade", 110);
	set_skill("yange-blade", 110);
	set_skill("force", 100);   
	set_skill("zhenyuan-force", 100);
	set_skill("literate", 120);
	set_skill("spells", 100);
	set_skill("taiyi", 100);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("blade", "yange-blade");
	map_skill("dodge", "baguazhen");

	set("max_kee", 700);
	set("max_sen", 700);
	set("force", 2000);
	set("max_force", 1100);
	set("mana", 2000);
	set("max_mana", 1100);	
	set("force_factor", 50);
	set("mana_factor", 50);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/blade/yanblade")->wield();
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
		command("say 好，那我就勉为其难吧。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}




