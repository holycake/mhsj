#include <ansi.h>
inherit NPC;

void random_move();

void create()
{
	string *ids;
	NPC_D->generate_cn_name(this_object());
	ids=parse_command_id_list();
	ids+=({ "boy" });
	set_name(name(),ids);
	set("gender", "男性" );
	set("age", 3+random(16));
	set("long", "这是京城当地居民家的男孩子，跑上街玩耍。他正是天真无邪的年纪。\n");
	set("per", 15+random(15));
	set("limit","nanjing");
	set("title", YEL"男孩"NOR);
	set("bodytype", NPC_D->get_random_bodytype());
	set("attitude", "friendly");
	set("scale", 150);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set_temp("born_time", time());

	setup();
    set("chat_chance", 30);
    set("chat_msg", ({
    	(: command("haha") :),
    	(: command("beauty") :),
    	(: random_move :)
    }
    ));
	//carry_object("/d/nanjing/obj/mao_shi"+random(2))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();

	seteuid(getuid());
}

void random_move()
{
        NPC_D->random_move(this_object());
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
        	switch(random(11))
        	{
        	case 0: command("hoho "+(string)ob->query("id"));break;
        	case 1: command("xixi "+(string)ob->query("id"));break;
        	case 2: command("rob "+(string)ob->query("id"));break;
        	case 3: command("smile "+(string)ob->query("id"));break;
        	case 4: command("boring "+(string)ob->query("id"));break;
        	case 5: command("hehe");break;
        	case 6: command("boring");break;
        	case 7: command("step2");break;
        	case 8: command("xixi");break;
        	case 9: command("smile");break;
        	case 10: command("slash");break;
        	}
	return;
}
