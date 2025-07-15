#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	string *ids;
	NPC_D->generate_cn_name(this_object());
	ids=parse_command_id_list();
	ids+=({ "shenji", "shenjiying", "huochong", "bing" });
	set_name(name(),ids);
	set("long", "大明神机营火铳手。\n");
	set("title", RED"神机营火铳手"NOR);
//	set("nickname", HIM "四娘" NOR);
	set("gender", "男性");
	set("age", 18+random(18));
	set("per", 15+random(15));
	set("attitude", "friendly");
	set("shen_type", 1);

	set("kee", 1700);
	set("max_kee", 1700);
	set("sen", 800);
	set("max_sen", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set_skill("unarmed", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("blade", 280);
	set_skill("force", 280);
	set_skill("dan-dao", 280);
	map_skill("blade","dan-dao");
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 90);
	set_temp("apply/armor", 40);
	set_temp("handing", carry_object("/d/nanjing/obj/gun3"));

	setup();
	carry_object("/d/nanjing/obj/mao_gun")->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/skirt_gun")->wear();
	carry_object("/d/nanjing/obj/armor_gun")->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	carry_object("/d/nanjing/obj/blade_yao")->wield();
//	carry_object("/d/nanjing/obj/gun3")->hand();
	carry_object("/d/nanjing/obj/bullet")->set_amount(200);
	add_money("silver",3+random(7));

	set("chat_chance", 9);
	set("chat_msg", ({
		WHT""+query("name")+"将铅弹放入后膛，然后将火药包填塞进去。\n"NOR,
		WHT""+query("name")+"举起枪瞄准靶子。。。\n"NOR,
		WHT"“啪”，一阵轻烟从"+query("name")+"的枪管冒出。居然是最新式的无烟火药。\n"NOR,
	}) );
	seteuid(getuid());
}

void init()
{
	object ob;

	::init();
/*
	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}*/
}

void greeting(object ob)
{
/*	if (!ob || environment(ob) != environment()) return;
        	switch(random(12))
        	{
        	case 0: command("wanfu "+(string)ob->query("id"));break;
        	case 1: command("xixi "+(string)ob->query("id"));break;
        	case 2: command("sister "+(string)ob->query("id"));break;
        	case 3: command("smile "+(string)ob->query("id"));break;
        	case 4: command("rose2 "+(string)ob->query("id"));break;
        	case 5: command("boring "+(string)ob->query("id"));break;
        	case 6: command("hehe");break;
        	case 7: command("boring");break;
        	case 8: command("wanfu");break;
        	case 9: command("xixi");break;
        	case 10: command("smile");break;
        	case 11: command("rose2");break;
        	}*/
	return;
}
