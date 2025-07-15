#include <ansi.h>
inherit NPC;

void random_move();

void create()
{
	string *ids;
	NPC_D->generate_girl_name(this_object());
	ids=parse_command_id_list();
	ids+=({ "shaonv" });
	set_name(name(),ids);
	set("gender", "女性" );
	set("age", 14+random(7));
	set("long", "这是京城当地居民家的女孩子，正在街上闲逛。\n她花枝招展，含苞欲放。给街上增添了靓丽的风景。\n");
	set("per", 20+random(10));
	set("limit","nanjing");
	set("title", HIM"南京少女"NOR);
	set("bodytype", NPC_D->get_random_bodytype());
	set("attitude", "friendly");
	set("scale", 150);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set_temp("born_time", time());

	setup();
    set("chat_chance", 30);
    set("chat_msg", ({
    	(: command("xixi") :),
    	(: command("rose") :),
    	(: random_move :)
    }
    ));
	carry_object("/d/nanjing/obj/mao_girl"+(5+random(11)))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
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
        	switch(random(13))
        	{
        	case 0: command("wanfu "+(string)ob->query("id"));break;
        	case 1: command("xixi "+(string)ob->query("id"));break;
        	case 2: command("sister "+(string)ob->query("id"));break;
        	case 3: command("smile "+(string)ob->query("id"));break;
        	case 4: command("boring "+(string)ob->query("id"));break;
        	case 5: command("follow "+(string)ob->query("id"));break;
        	case 6: command("follow none");break;
        	case 7: command("hehe");break;
        	case 8: command("boring");break;
        	case 9: command("wanfu");break;
        	case 10: command("xixi");break;
        	case 11: command("smile");break;
        	case 12: command("rose2");break;
        	}
	return;
}
