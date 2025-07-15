#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("寇白门", ({ "kou baimen", "kou", "baimen" }));
	set("long", HIM"宝髻巍峨，风姿绰约。容貌冶艳，娟娟静美。若非绮阁生成，定是兰房长就。俨\n若紫府琼姬离碧汉，宛如蕊宫仙子下尘寰。 \n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "女侠" NOR);
	set("gender", "女性");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 34);

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));
	set("chat_chance", 2);
	set("chat_msg", ({
		"寇白门将白子放入棋盘，说道：二間高夾。\n",
		"寇白门下定棋子，说道：小飛進角。\n",
		"寇白门说道：姊姊可要输了哦。\n",
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
