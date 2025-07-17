#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	string *ids;
	NPC_D->generate_cn_name(this_object());
	ids=parse_command_id_list();
	ids+=({ "yulin", "bing" });
	set_name(name(),ids);
	set("long", "大明羽林卫的士兵，专门负责保卫皇宫的安全。\n");
	set("title", MAG"羽林卫皇城守卫"NOR);
//	set("nickname", HIM "四娘" NOR);
	set("gender", "男性");
	set("age", 18+random(18));
	set("per", 20+random(10));
	set("attitude", "friendly");
	set("shen_type", 1);

	set("kee", 1900);
	set("max_kee", 1900);
	set("sen", 800);
	set("max_sen", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set_skill("unarmed", 260);
	set_skill("dodge", 260);
	set_skill("parry", 260);
	set_skill("blade", 260);
	set_skill("force", 260);
	set_skill("dan-dao", 260);
	map_skill("blade","dan-dao");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);
/*
	set("chat_chance", 2);
	set("chat_msg", ({
		WHT"火铳手将铅弹放入后膛，然后将火药包填塞进去。\n"NOR,
		WHT"火铳手举起枪瞄准靶子。。。\n"NOR,
		WHT"“啪”，一阵轻烟从火铳手的枪管冒出。\n居然是最新式的无烟火药。\n"NOR,
	}) );
*/
	setup();
	carry_object("/d/nanjing/obj/mao_bing")->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	//carry_object("/d/nanjing/obj/skirt_gun")->wear();
	carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	carry_object("/d/nanjing/obj/blade_yao")->wield();
	add_money("silver",3+random(7));
	seteuid(getuid());
}

void init()
{
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
