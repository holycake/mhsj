#include <ansi.h>
inherit NPC;

void random_move();

void create()
{
	string *ids;
	NPC_D->generate_cn_name(this_object());
	ids=parse_command_id_list();
	ids+=({ "jian sheng", "jiansheng", "shu sheng", "shusheng" });
	set_name(name(),ids);
	set("gender", "男性" );
	set("age", 11+random(9));
	set("long", "国子监生员，皆为国内优秀的人才选拔而出。");
	set("per", 20+random(10));
	set("limit","nanjing");
	set("title", HIC"监生"NOR);
	set("bodytype", NPC_D->get_random_bodytype());
	set("attitude", "friendly");
	set("scale", 150);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 50);
	set_temp("born_time", time());

	setup();
    set("chat_chance", 30);
    set("chat_msg", ({
    	(: command("haha") :),
    	(: command("beauty") :),
    	(: random_move :)
    }
    ));
	carry_object("/d/nanjing/obj/mao_shi"+random(2))->wear();
	carry_object("/d/nanjing/obj/cloth_shi"+random(4))->wear();
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
        	case 0: command("love1");break;
        	case 1: command("beauty "+(string)ob->query("id"));break;
        	case 2: command("sister "+(string)ob->query("id"));break;
        	case 3: command("smile "+(string)ob->query("id"));break;
        	case 4: command("bow "+(string)ob->query("id"));break;
        	case 5: command("hehe");break;
        	case 6: command("poem");break;
        	case 7: command("stay");break;
        	case 8: command("sorry2");break;
        	case 9: command("smile");break;
        	case 10: command("rose2");break;
        	}
	return;
}
