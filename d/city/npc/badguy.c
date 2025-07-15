//By waiwai@mszj 2000/11/13

void consider();

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("地主老豺", ({ "dizhu laochai", "dizhu", "laochai" }) );
        set("long",CYN
"一个满脸伤疤加横肉的家伙,专门干榨取长工血汗的勾当，暗地里还杀人越货无所不做。\n"NOR);
       set("attitude", "aggressive");
//        set("attitude", "friendly");
        set("per", 1);
        set("combat_exp", 100000+random(4000000));
        set("bellicosity", 10000);
        set("chat_chance", 30);
        set("chat_msg", ({HIB
                "地主老豺喝道：今天老子要钱又要命！！\n"NOR,
                HIB"地主老豺笑道：小样，去死吧！\n"NOR,
		(: random_move :),
        }) );

        set_skill("unarmed", 70+random(200));
        set_skill("blade", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200));
        set_skill("stealing", 600);

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(400));
        set_temp("apply/move", 100);

        setup();
       carry_object("/d/city/obj/xiangyan")->set_amount(3);
        carry_object("/d/city/obj/gourou")->set_amount(5);
        carry_object("/d/city/obj/yexing")->wear();
        carry_object("/d/city/obj/guiblade")->wield();

}

void init()
{	
	object ob;

	set_heart_beat(1);
	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("dizhu");
		call_out("dizhu", 1, ob);
	}
}

void dizhu(object ob)
{
	switch( random(2) ) {
		case 0:
                       command("kill ob");
                       command("look " + ob->query("id"));
                       command("follow " + ob->query("id"));
                       command ("grin");
                       command("xiyan");
		       break;

		case 1:
                       command("look " + ob->query("id"));
                       command("follow " + ob->query("id"));
                       command ("grin");
                       command("eat gourou");
                       break;
	}
}

