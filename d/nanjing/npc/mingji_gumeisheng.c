#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("顾眉生", ({ "gu meisheng", "gu", "meisheng" }));
	set("long", HIM"庄妍靓雅，风度超群。鬓发如云，桃花满面。弓弯纤小，腰肢轻亚。俊眼修眉，\n顾盼神飞，文彩精华，见之忘俗。\n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "横波" NOR);
	set("gender", "女性");
	set("age", 17);
	set("per", 32);
	set("attitude", "friendly");
	set("shen_type", 1);

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));

	set("chat_chance", 2);
	set("chat_msg", ({
		"顾眉生蹙着眉看着棋局，一副若有所思的样子。\n",
		"顾眉生看着刚落定的棋子，点了点头。\n",
		"顾眉生背着手在船舱里踱起步来。\n",
	}) );
	seteuid(getuid());
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
        	}
	return;
}
