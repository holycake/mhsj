// yan.c 执阵

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("执阵道长", ({ "zhi zhen" }));
        set("long","他不过三十出头年纪，双腿却残废，荡魔天尊命他主持真武剑阵。\n");
        set("gender", "男性");
        set("age", 31);
        set("attitude", "peaceful");
        set("str", 25);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force", 2500);
	set("max_force", 2500);
	set("combat_exp", 1200000);

        set_skill("force", 100);
        set_skill("dodge", 150);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
	set_skill("spells", 200);
	
	map_skill("spells", "dao");

	set("chat_chance", 1);

        set("chat_msg", ({
            "执阵道长说道：真武剑阵是恩师的心血。",
            "执阵道长仰天叹道：妖魔当道，何人能除？"
        }));

        create_family("武当派", 2, "弟子");

        setup();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}
