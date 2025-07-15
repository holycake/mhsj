// by gslxz@mhsj 2001/11/21 (优化)
// bonze.c 和尚
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("和尚", ({ "heshang", "bonze" }));
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 800);
	set("max_gin", 800);
	set("max_sen", 800);
	set("force", 1800);
	set("max_force", 900);
	set("force_factor", 30);
	set("max_mana", 900);
	set("mana", 1800);
	set("mana_factor", 30);
	set("combat_exp", 500000);
	set("daoxing", 300000);


        set("eff_dx", 35000);
        set("nkgain", 200);

	set_skill("literate", 90);
	set_skill("spells", 90);
	set_skill("buddhism", 90);
	set_skill("unarmed", 90);
	set_skill("jienan-zhi", 90);
	set_skill("dodge", 100);
	set_skill("lotusmove", 100);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("lotusforce", 90);
	set_skill("staff", 100);
	set_skill("lunhui-zhang", 110);
//	set_skill("spear", 30);
//	set_skill("huoyun-qiang", 30);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );
        
	create_family("南海普陀山", 3, "弟子");
	
	setup();
	carry_object("/obj/money/silver");
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void attempt_apprentice(object ob)
{
	command("smile");
	command("say 很好，贫僧就收下你，希望你多加努力，早成正果。\n");

	command("recruit " + ob->query("id") );
	 message("shout", WHT "【"HIC"门派消息"NOR+WHT"】："+ WHT"南海普陀山又多了一个弟子"+YEL""+this_player()->name()+WHT"南海普陀山的势力加强了。\n"NOR,users());
return;
}


