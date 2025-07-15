#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIR"清虚道长"NOR, ({ "qingxu daozhang", "daozhang" }));
	set("title", "复真观主管");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("spi", 28);
	
	set("mana", 5000);
	set("max_mana", 5000);
	set("force", 5000);
	set("max_force", 5000);
	set("combat_exp", 3139063);
	set("daoxing", 5390000);

	set_skill("force", 200);
	set_skill("wudang-force", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("wudang-spells", 200);
	set_skill("literate", 200);
	set_skill("spells", 200);

	map_skill("spells", "wudang-spells");
	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");
	set("class", "taoist");
            
            setup();

            carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	carry_object("/d/wudang1/obj/whiterobe")->wear();
}

