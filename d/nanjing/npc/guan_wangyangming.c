#include <ansi.h>

inherit NPC;

string ask_job();
void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("王守仁", ({ "wang shouren", "yangming", "yangmingzi", "wang", "shouren" }));
	set("long", "圣人阳明子，如今下界帮助大明。\n");
	set("title", HIM"新建公"NOR);
	set("degree", RED "正一品 特进光禄大夫上柱国" NOR);
	set("gender", "男性");
	set("age", 100);
	set("per", 35);
	set("attitude", "friendly");
	set("shen_type", 1);

	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("force", 300);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 400);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 400);
	 set("inquiry", ([
	                   "监生"    : (: ask_job :),
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
	carry_object("/d/nanjing/obj/cloth_guan2")->wear();
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

string ask_job()
{
	object ob=this_player();
	if ( time() - ob->query_temp("last_time/feat") < 360 ){
		command("say "+ob->query("name")+"，你不是刚问过吗？\n");
		return "还是过一会再来吧。";
	}
	if (ob->query_skill("literate")< 100)
		return "进太学需得有些基础才好。这位"+ RANK_D->query_respect(ob) +"还是先学些识文断字的基础（literate>=100）吧。\n";
	if (ob->query_skill("literate")>=100 && ob->query("feat")<100)
	{
		ob->set_temp("last_time/feat",time());
		ob->set("degree", "国子监生员");
		command("nod");
		command("smile");
		message("channel:chat",HIY+"王守仁(wang shouren)：如今时局艰难，老夫特招"+ob->query("name")+"为国子监生员。冀其能为国效力。\n"+NOR,users());
		return "汝既为监生，可往率性堂协助沈典籍抄写永乐大典。\n";
	}
	return "老夫虽已位列仙班，却不忍我民生灵涂炭，故此下界。今蒙上厚爱，掌太学。";
}
