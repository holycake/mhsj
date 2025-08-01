#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_job();
void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("朱万年", ({ "zhu wannian", "zhu", "wannian", "zhihui", "jiang" }));
	set("long", "南京中城兵马司指挥。\n");
	set("title", HIR"指挥"NOR);
	set("degree", HIC "正六品 承直郎" NOR);
	set("gender", "男性");
	set("age", 45);
	set("per", 26);
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
/*
	set("chat_chance", 2);
	set("chat_msg", ({
		WHT"火铳手将铅弹放入后膛，然后将火药包填塞进去。\n"NOR,
		WHT"火铳手举起枪瞄准靶子。。。\n"NOR,
		WHT"“啪”，一阵轻烟从火铳手的枪管冒出。\n居然是最新式的无烟火药。\n"NOR,
	}) );
*/
        set("inquiry", ([
                "job"    : (: ask_job :),
        ]));
	setup();
	carry_object("/d/nanjing/obj/mao_guan")->wear();
	carry_object("/d/nanjing/obj/cloth_guan0")->wear();
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
	object me;
	object ob;
	int b;

	me = this_player();

	if (me->query("feat") < 1300){
		return "本官看足下年轻有为，将来必成大气。还应在国子监多多学习才是。鄙署虽然人手紧张，却也应付得来。";
	}

	if (me->query("feat") >= 2000){
		return "大人在这里着实帮了不少忙。时下正值国家用人之际，余已跟铨部打过招呼了，大人可去文选司问问是否有缺。";
	}

	if (me->query_temp("step/wulai") >= 10){
		b = 100 + random(100);
		me->add("combat_exp", b);
		me->improve_potential(b);
		ob = new("/obj/money/coin");
		ob->set_amount(70);
		ob->move(me, 1);
		if (b > 0){
			tell_object(me, HIC "\n你获得了" +chinese_number(b) +"点经验和潜能，还有一些辛苦费。\n" NOR);
		}
		me->add("feat",1);
		me->add("score",1+random(10));
		me->add("weiwang",1+random(10));
		me->add("shen",1+random(10));
		me->delete_temp("job/wulai");
		me->delete_temp("step/wulai");
		me->delete("quest");
		tell_object(me, HIM "\n你的江湖阅历、威望和朝廷功勋增加了。\n\n\n" NOR);
		return "干得好，这下总算可以耳根清净会了。";
	}
	if (me->query_temp("step/wulai") < 10 && me->query_temp("job/wulai") == 1){
		return "三山门一带的泼皮无赖可是教训过了？";
	}
	if (me->query("kee") < 5)
		return "你还是先歇歇吧，万一累出人命来我可负担不起。";

	if (! interactive(me))
		return "...";

	me->delete_temp("job/wulai");
	me->delete_temp("step/wulai");
	me->set_temp("job/wulai", 1);
	me->set("quest/name", "无赖");
	me->set("quest/type", "feat");
	me->set("quest/place", "三山门一带");
	me->set("quest/master_name", "朱万年");
	return "好，近有一班泼皮无赖在三山门一带生事，贵官可私下替余教训一番。";
}
