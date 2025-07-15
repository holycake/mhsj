// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("王方平", ({ "wang fangping", "wang", "fangping" }));

set("long","王方平本是山中道士，后在丰都山同阴长生同修炼成仙，御封(「鬼王」。\n");
        set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", YEL"轮回司主"NOR);
	set("nickname", "鬼王");
        set("combat_exp", 1850000);
  set("daoxing", 1000000);

        set("max_gin", 1400);
        set("max_kee", 1400);
        set("max_sen", 1400);
	set("class", "youling");
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 2000);
	set("mana", 4000);
	set("mana_factor", 100);

	set_skill("literate", 160);
	set_skill("ghost-steps", 190);
        set_skill("dodge", 190);
        set_skill("unarmed", 170);
	set_skill("parry", 170);
	set_skill("spells", 170);
	set_skill("gouhunshu", 170);
	set_skill("jinghun-zhang", 170);
	set_skill("force", 200);
	set_skill("tonsillit", 200);
	set_skill("stick", 180);
	set_skill("kusang-bang", 180);

	map_skill("stick","kusang-bang");
	map_skill("parry", "kusang-bang");
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
//                (: exert_function, "powerup" :),
                (: exert_function, "sheqi" :),
                (: cast_spell, "gouhun" :),
        }) );


        set("nkgain", 400);

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


create_family("阎罗地府", 2, "你好");

        setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
       command("recruit " + me->query("id") );
	me->set("class", "youling");
	 message("shout", WHT "〖"HIC"门派消息"NOR+WHT"〗："+ WHT"阎罗地府又多了一个弟子"+YEL""+this_player()->name()+WHT"阎罗地府的势力加强了。\n"NOR,users());
 return;
}
/*
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
		ob->set("title", "地府招魂司阴兵");
}

*/

