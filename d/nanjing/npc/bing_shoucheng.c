#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	string *ids;
	NPC_D->generate_cn_name(this_object());
	ids=parse_command_id_list();
	ids+=({ "wucheng", "bing" });
	set_name(name(),ids);
	set("long", "五城兵马司所属的维护京城治安的士兵。\n");
	set("title", YEL"五城兵马司京城守卫"NOR);
//	set("nickname", HIM "四娘" NOR);
	set("gender", "男性");
	set("age", 18+random(18));
	set("per", 15+random(15));
	set("attitude", "friendly");
	set("shen_type", 1);

	set("kee", 1500);
	set("max_kee", 1500);
	set("sen", 800);
	set("max_sen", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set_skill("unarmed", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("blade", 220);
	set_skill("force", 220);
	set_skill("dan-dao", 220);
	map_skill("blade","dan-dao");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);

	setup();
	carry_object("/d/nanjing/obj/mao_bing")->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	//carry_object("/d/nanjing/obj/skirt_gun")->wear();
	carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	carry_object("/d/nanjing/obj/blade_yao")->wield();
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
	object wp;
	
	if (!ob || environment(ob) != environment()) return;

	if (!ob->query_temp("weapon"))
	{
		switch(random(7))
		{
			case 0: command("look "+(string)ob->query("id"));break;
			default:break;
		}
	} else
	{
		wp=ob->query_temp("weapon");
		switch(random(8))
		{
			case 0: command("look "+(string)ob->query("id"));break;
			case 1: command("look "+(string)wp->query("id")	+" of "+(string)ob->query("id"));break;
			default:break;
		}
	}
	return;
}
