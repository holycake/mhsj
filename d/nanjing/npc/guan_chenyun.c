#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_job();
string ask_for_officer();
void greeting(object ob);

string * degree_desc = ({
       HIG "从九品 将仕佐郎" NOR,	//100
       HIG "从九品 登仕佐郎" NOR,	//200
       HIG "正九品 将仕郎" NOR,	//300
       HIG "正九品 登仕郎" NOR,	//400
       HIG "从八品 迪功佐郎" NOR,	//500
       HIG "从八品 修职佐郎" NOR,	//600
       HIG "正八品 迪功郎" NOR,	//700
       HIG "正八品 修职郎" NOR,	//800
       HIC "从七品 从仕郎" NOR,	//900
       HIC "从七品 徵仕郎" NOR,	//1000
       HIC "正七品 承事郎" NOR,	//1100
       HIC "正七品 文林郎" NOR,	//1200
       HIC "从六品 承务郎" NOR,	//1300
       HIC "从六品 儒林郎" NOR,	//1400
       HIC "正六品 承直郎" NOR,	//1500
       HIC "正六品 承德郎" NOR,	//1600
       HIC "从五品 奉训大夫" NOR,	//1700
       HIC "从五品 奉直大夫" NOR,	//1800
       HIC "从五品 奉直大夫协正庶尹" NOR,	//1900
       HIC "正五品 奉议大夫协正庶尹" NOR,	//2000
       HIC "正五品 奉政大夫协正庶尹" NOR,	//2100
       HIC "正五品 奉政大夫修正庶尹" NOR,	//2200
       RED "从四品 朝列大夫修正庶尹" NOR,	//2300
       RED "从四品 朝议大夫修正庶尹" NOR,	//2400
       RED "从四品 朝议大夫赞治少尹" NOR,	//2500
       RED "正四品 中顺大夫赞治少尹" NOR,	//2600
       RED "正四品 中宪大夫赞治少尹" NOR,	//2700
       RED "正四品 中宪大夫赞治尹" NOR,	//2800
       RED "从三品 亚中大夫赞治尹" NOR,	//2900
       RED "从三品 中大夫赞治尹" NOR,	//3000
       RED "从三品 中大夫资治少尹" NOR,	//3100
       RED "正三品 嘉议大夫资治少尹" NOR,	//3200
       RED "正三品 通议大夫资治少尹" NOR,	//3300
       RED "正三品 正议大夫资治少尹" NOR,	//3400
       RED "正三品 正议大夫资治尹" NOR,	//3500
       RED "从二品 中奉大夫资治尹" NOR,	//3600
       RED "从二品 通奉大夫资治尹" NOR,	//3700
       RED "从二品 正奉大夫资治尹" NOR,	//3800
       RED "从二品 正奉大夫正治卿" NOR,	//3900
       RED "正二品 资善大夫正治卿" NOR,	//4000
       RED "正二品 资政大夫正治卿" NOR,	//4100
       RED "正二品 资德大夫正治卿" NOR,	//4200
       RED "正二品 资德大夫正治上卿" NOR,	//4300
       RED "从一品 荣禄大夫正治上卿" NOR,	//4400
       RED "从一品 光禄大夫正治上卿" NOR,	//4500
       RED "从一品 光禄大夫柱国" NOR,	//4600
       RED "正一品 特进荣禄大夫柱国" NOR,	//4700
       RED "正一品 特进荣禄大夫左柱国" NOR,	//4800
       RED "正一品 特进光禄大夫左柱国" NOR,	//4900
       RED "正一品 特进光禄大夫右柱国" NOR,	//5000
       RED "正一品 特进光禄大夫上柱国" NOR,	//5100
});

void create()
{
	seteuid(getuid());
	set_name("陈云", ({ "chen yun", "chen", "yun", "langzhong", "guan" }));
	set("long", "吏部文选清吏司郎中。\n");
	set("title", HIR"郎中"NOR);
	set("degree", HIC "正五品 奉议大夫协正庶尹" NOR);
	set("gender", "男性");
	set("age", 45);
	set("per", 25);
	set("attitude", "friendly");
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
/*
	set("chat_chance", 2);
	set("chat_msg", ({
		HIG"火铳手将铅弹放入后膛，然后将火药包填塞进去。\n"NOR,
		HIG"火铳手举起枪瞄准靶子。。。\n"NOR,
		HIG"“啪”，一阵轻烟从火铳手的枪管冒出。\n居然是最新式的无烟火药。\n"NOR,
	}) );
*/
        set("inquiry", ([
                "功勋"    : (: ask_for_officer :),
                "出缺"    : (: ask_job :),
        ]));
	setup();
	carry_object("/d/nanjing/obj/mao_guan")->wear();
	carry_object("/d/nanjing/obj/cloth_guan1")->wear();
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
	int lv;
	object ob=this_player(),me=this_object();

	lv = (ob->query("feat")-100)/100;

	if (lv >= sizeof(degree_desc))
		lv = sizeof(degree_desc)-1;

	ob->set_temp("last_time/feat",time());
	ob->set("degree", degree_desc[lv]);

	if (ob->query("feat") < 2000){
		command("smile");
		return "贵官为"+degree_desc[lv]+"，当下并无实缺可补。还是在国子监好好学习吧。";
	}

	if (ob->query("feat") >= 2000){
		command("nod");
		message_vision(HIW "$N找出$n的履历看了看，喃喃念道："+degree_desc[lv]+ HIW"，于兵部观政。\n\n" NOR, me,ob);
		return "现下朝廷与虏、逆两线作战，边事艰难。\n贵官此去兵部观政，既能为国家出力，救我百姓于水火，也能为个人积累些功勋。";
	}

	return "若尔有志报效国家，还需多多磨练自身才是。";
}

string ask_for_officer()
{
	int lv;
	object ob=this_player();
	if (ob->query("feat")<100){
		ob->delete("degree");
		return "足下当前并无官阶。";}
	lv = (ob->query("feat")-100)/100;

	if (lv >= sizeof(degree_desc))
		lv = sizeof(degree_desc)-1;

	if ( time() - ob->query_temp("last_time/feat") < 120 ){
		command("say "+ob->query("name")+"，你不是刚问过吗？\n");
		return "还是过一会再来吧。";
	}

	ob->set_temp("last_time/feat",time());
	ob->set("degree", degree_desc[lv]);
	command("nod");
	command("smile");
	if (ob->query("feat") >= 1600)
	{
		message("channel:chat",HIY+"【圣旨】陈云(chen yun)：今奉皇帝玉旨，加封"+ob->query("name")+"为"+degree_desc[lv]+HIY"，于兵部观政。钦此！\n"+NOR,users());
		command("gongxi");
		return "现下朝廷与虏、逆两线作战，边事艰难。\n贵官此去兵部观政，既能为国家出力，救我百姓于水火，也能为个人积累些功勋。\n";
	}
	else
	{
		message("channel:chat",HIY+"【圣旨】陈云(chen yun)：今奉皇帝玉旨，加封"+ob->query("name")+"为"+degree_desc[lv]+HIY"。钦此！\n"+NOR,users());
		command("gongxi");
		return "现下虽不封授实缺，仅为朝廷冗官。\n但国家正值用人之际，贵官更当为国为民尽心竭力才是。\n";
	}
}
