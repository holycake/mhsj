#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("朱由检", ({ "zhu youjian", "zhu", "youjian", "huangdi", "bixia", "huang" }));
	set("long", "大明第十七帝，讳由检，字德约。当日闯逆攻打北京，崇祯陛下南狩留都，于此定\n都。抵御闯逆、后金。\n");
	set("title", HIY"大明崇祯皇帝"NOR);
//	set("nickname", HIM "四娘" NOR);
	set("gender", "男性");
	set("age", 33);
	set("per", 30);
	set("attitude", "friendly");
	set("shen_type", 1);

	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("blade", 120);
	set_skill("force", 120);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
/*
	set("chat_chance", 2);
	set("chat_msg", ({
		WHT"火铳手将铅弹放入后膛，然后将火药包填塞进去。\n"NOR,
		WHT"火铳手举起枪瞄准靶子。。。\n"NOR,
		WHT"“啪”，一阵轻烟从火铳手的枪管冒出。\n居然是最新式的无烟火药。\n"NOR,
	}) );
*/
	setup();
	carry_object("/d/nanjing/obj/mao_yishan")->wear();
	carry_object("/d/nanjing/obj/cloth_huang"+random(5))->wear();
	//carry_object("/d/nanjing/obj/skirt_gun")->wear();
	//carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	//carry_object("/d/nanjing/obj/blade_yao")->wield();
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
