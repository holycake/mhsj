#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("柳如是", ({ "liu rushi", "liu", "rushi" }));
	set("long", HIM"只见她生得削肩细腰，长挑身材。俊眼修眉，顾盼神飞。腻粉妆成脖颈，花钿巧\n帖眉尖。举止惊人，貌比幽花殊丽；姿容闲雅，性如兰蕙温柔。\n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "蘼芜" NOR);
	set("gender", "女性");
	set("age", 17);
	set("per", 33);
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
		"柳如是将黑子放入棋盘，说道：小飛掛。\n",
		"柳如是下定棋子，说道：一間跳。\n",
		"柳如是说道：妹妹小心了。\n",
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
