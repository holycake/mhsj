// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("清风", ({ "qing feng", "qing", "feng" }));
	set("long", 
		"他是武当山的小道童。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");

	set("str", 20);

	set("combat_exp", 615763);
	set("daoxing", 500000);
	set("max_force", 1500);
       set("force", 3000);
       set("max_mana", 1500);
       set("mana", 3000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("spells", 150);
	set_skill("wudang-force", 150);
	set_skill("wudang-spells", 150);
	set_skill("taiji-jian", 150);
	set_skill("tiyunzong", 150);
	set_skill("sword", 150);
	set_skill("parry", 150);
	set_skill("literate", 120);
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("force", "wudang-force");
	map_skill("spells", "wudang-spells");
	map_skill("dodge", "tiyunzong");

	create_family("武当派", 4, "弟子");

	setup();
	
	carry_object("/d/wudang1/obj/bluecloth")->wear();
       carry_object("/d/wudang1/obj/tiejian")->wield();
}
void attempt_apprentice(object ob)
{
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们武当发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");	
}
