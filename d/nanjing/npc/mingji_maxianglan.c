#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("马湘兰", ({ "ma xianglan", "ma", "xianglan" }));
	set("long", HIM"秉性灵秀，姿首如常人，神情开涤，濯濯如春柳早莺，吐辞流盼，巧伺人意。檀\n口轻开，勾引得蜂狂蝶乱；纤腰拘束，暗带着月意风情。\n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "四娘" NOR);
	set("gender", "女性");
	set("age", 17);
	set("per", 30);
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
		"马湘兰用手指夹起一小块虎皮肉，丢进嘴里。一脸地满足。\n",
		"马湘兰端起一碟醉蛤闻了闻，说道：好香啊。\n",
		"马湘兰拿起一个杯子抿了一口，说道：姊姊的秋海棠露真是不负虚名呀。\n",
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
