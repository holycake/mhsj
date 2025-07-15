#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("卞赛赛", ({ "bian saisai", "bian", "saisai" }));
	set("long", HIM"月画烟描，粉妆玉琢。俊庞儿不肥不瘦，俏身材难减难增。仪容娇媚，体态轻盈\n。谈吐如云，令人倾倒。\n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "玉京道人" NOR);
	set("gender", "女性");
	set("age", 18);
	set("per", 31);
	set("attitude", "friendly");
	set("shen_type", 1);

	setup();

	set("chat_chance", 2);
	set("chat_msg", ({
		"卞赛赛抚着古琴说：小妹新近打谱了曲鸥鹭忘机，请几位姊姊指正。\n",
		"卞赛赛听着琴曲，有些出神。\n",
		"卞赛赛听着琴曲，看着沿岸的景色。\n",
	}) );
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));
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
