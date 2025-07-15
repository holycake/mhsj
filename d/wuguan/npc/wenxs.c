//Cracked by Roath
// zhu.c 文先生

inherit NPC;

#include <ansi.h>

int ask_zixue();

void create()
{
	set_name("文先生", ({ "wen xiansheng", "teacher","wen","xiansheng" }));
	set("long",
"文先生被称为东方武馆中颇有些墨水的人。\n");
	set("gender", "男性");
	set("age", 65);
	set_skill("literate", 60);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);
	set("combat_exp", 80000);
	set("shen_type", 1);
	set("inquiry",([
		"自学":		(:ask_zixue:),
		]));
	
	setup();
}

void init()
{
	object ob=this_player();
	::init();
	
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	return;
}

int recognize_apprentice(object ob)
{
	int money=25, level = ob->query_skill("literate", 1);

	if(level>30) money=50;
	if(level>50) money=100;
	if(level>100) money=500;
	if(level>150) money=800;
	if(level>200) money=1000;
	if(level>250) money=1500;

	if(!ob->query("wuguan/join")) return 0;
	ob->delete_temp("mark/literate");
	switch(MONEY_D->player_pay(ob, money))
	{
		case 0:
		case 2:
			tell_object(ob,"你现在的学费是每次" + MONEY_D->money_str(money) + "，请备好零钱。\n");
			return 1;
			break;
	}
	ob->set_temp("mark/literate",1);
	return 1;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob->query_skill("literate") > 60 ) return;
	
	command("pat "+ob->query("id"));
	command("say 这位" + RANK_D->query_respect(ob)


                                + "，到我这学些知识"HIY"(xue wen literate)"NOR"吧。");
}

int is_apprentice_of()
{
	return 1;
}

int ask_zixue()
{
	object ob=this_player();
	
	if(!ob->query("wuguan/join"))
	{
		command("say 你并非我武馆的成员，要想自学也别找我呀。");
		return 1;
	}
	if(ob->query_skill("literate",1)<10)
	{
		command("say 你这个文盲，还会自学？");
		return 1;
	}
	if(ob->query_skill("literate",1)<60)
	{
		command("say 就你这点水平，还自学什么？");
		return 1;
	}
	if(ob->query_temp("wuguan/zixue"))
	{
		command("say 这个问题我不是给你解答过了么？怎么又来问！");
		command("walkby "+ob->query("id"));
		command("say 就你这种水平也能自学？");
		return 1;
	}
	
	command("whisper "+ob->query("id")+
	" 书房里有些书，以你现在的能力，应该能看懂。你去找找吧。");
	ob->set_temp("wuguan/zixue",1);
	return 1;
}
	
