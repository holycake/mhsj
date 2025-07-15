#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("周玉凤", ({ "zhou yufeng", "zhou", "yufeng", "huanghou", "hou" }));
	set("long", "她端庄美丽，肌肤洁白如玉，国色。\n");
	set("title", HIY"大明皇后"NOR);
	//set("nickname", HIM "四娘" NOR);
	set("gender", "女性");
	set("age", 34);
	set("per", 32);
	//set("level", 8);
	set("attitude", "friendly");
	set("shen_type", 1);
/*
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

*/
	setup();
	carry_object("/d/nanjing/obj/mao_hou")->wear();
	carry_object("/d/nanjing/obj/cloth_hou0")->wear();
	carry_object("/d/nanjing/obj/skirt_hou"+random(3))->wear();
	//carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	//carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	//carry_object("/d/nanjing/obj/blade_yao")->wield();
	add_money("silver",3+random(7));
	set("chat_chance", 2);
	set("chat_msg", ({
		MAG"皇后娘娘正在为皇上缝补衣物。\n"NOR,
		MAG"皇后娘娘看着身前的小内侍说道：你且把昨日所学《大学》章节背来。\n"NOR,
		MAG"皇后娘娘说道：田妃妹妹这画功可益发精进了。\n"NOR,
		MAG"皇后娘娘说道：田妃妹妹可有兴致弹奏一曲？\n"NOR,
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
