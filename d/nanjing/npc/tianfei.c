#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("田秀英", ({ "tian xiuying", "tian", "xiuying", "fei" }));
	set("long", "她是崇祯陛下最宠爱的妃子。精通琴艺、书画。\n");
	set("title", HIM"贵妃"NOR);
	//set("nickname", HIM "四娘" NOR);
	set("gender", "女性");
	set("age", 33);
	set("per", 31);
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
	carry_object("/d/nanjing/obj/cloth_hou1")->wear();
	carry_object("/d/nanjing/obj/skirt_hou"+random(3))->wear();
	//carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	//carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	//carry_object("/d/nanjing/obj/blade_yao")->wield();
	add_money("silver",3+random(7));
	set("chat_chance", 2);
	set("chat_msg", ({
		MAG"田贵妃说道：新近作了一副兰花图，请皇后娘娘过目。\n"NOR,
		MAG"田贵妃说道：今日天气晴朗，皇后娘娘、田妃妹妹，不如同去蹴鞠？\n"NOR,
		MAG"田贵妃说道：这天气，倒适宜抚琴。\n"NOR,
		MAG"田贵妃说道：这是江南新近流行的衣服样式，皇后娘娘、田妃妹妹，觉得如何？\n"NOR,
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
