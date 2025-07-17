#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("袁表", ({ "yuan biao", "yuan", "biao", "zhihui", "jiang" }));
	set("long", "南京南城兵马司指挥。\n");
	set("title", HIR"指挥"NOR);
	set("degree", HIC "正六品 承直郎" NOR);
	set("gender", "男性");
	set("age", 43);
	set("per", 27);
	set("attitude", "friendly");
	set("shen_type", 1);

	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
	set_skill("force", 150);
	set_skill("dan-dao", 150);
	map_skill("blade","dan-dao");
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	 set("inquiry", ([
	                   "job": "本区无事，尊驾不妨去中城兵马司看看。",
	                ]) );
/*
	set("chat_chance", 2);
	set("chat_msg", ({
		WHT"火铳手将铅弹放入后膛，然后将火药包填塞进去。\n"NOR,
		WHT"火铳手举起枪瞄准靶子。。。\n"NOR,
		WHT"“啪”，一阵轻烟从火铳手的枪管冒出。\n居然是最新式的无烟火药。\n"NOR,
	}) );
*/
	setup();
	carry_object("/d/nanjing/obj/mao_guan")->wear();
	carry_object("/d/nanjing/obj/cloth_guan0")->wear();
	//carry_object("/d/nanjing/obj/skirt_gun")->wear();
	//carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	carry_object("/d/nanjing/obj/blade_yao")->wield();
	add_money("silver",3+random(7));
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
