// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIB"殷梨亭"NOR, ({ "ying liting", "ying" }));
	set("nickname", "武当六侠");
	set("long", 
		"他就是张三丰的六弟子殷梨亭。\n"
		"他今年三十岁，精明能干，嫉恶如仇，性如烈火。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("spi", 28);
	
	set("mana", 3500);
	set("max_mana", 3500);
	set("force", 3600);
	set("max_force", 3600);
	set("combat_exp", 3339063);
	set("daoxing", 2230000);

	set_skill("force", 250);
	set_skill("wudang-force", 250);
	set_skill("dodge", 250);
	set_skill("tiyunzong", 250);
	set_skill("unarmed", 250);
	set_skill("taiji-quan", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("taiji-jian", 250);
	set_skill("wudang-spells", 250);
	set_skill("literate", 200);
	set_skill("spells", 250);

	map_skill("spells", "wudang-spells");
	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");
	set("class", "taoist");
            
            setup();

            carry_object("/d/wudang1/obj/tiejian")->wield();
	carry_object("/d/wudang1/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="武当派") {
		if ((int)ob->query_skill("wudang-force", 1) < 200) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在武当心法上多下点功夫？");
		return;
	}
	if (((int)ob->query("daoxing") < 500000 )) {
	command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才是。\n");
	return;
	}
        command("smile");
	command("say 好极，好极，时下妖魔当道，鬼怪横行。象"  + RANK_D->query_respect(ob) +
"这样的正义之士却是少见！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say 本人不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ){
                ob->set("class", "taoist");
}
        return 0;
}

