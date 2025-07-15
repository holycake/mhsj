//Cracked by Roath
// zhaowushi.c

inherit NPC;

#include <ansi.h>

int ask_kungfu();

void create()
{
        set_name("赵武师", ({ "zhao wushi", "zhao","wushi" }));
        set("long", "赵武师是馆主的得力助手之一。\n");
        set("gender", "男性");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);
		set("inquiry",([
			"功夫":		(:ask_kungfu:),
			]));
        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	object ob=this_player();
	
	::init();
	
	if(interactive(ob) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
	return ;
}
		
int recognize_apprentice(object ob)
{
	if(!ob->query("wuguan/join")) return 0;
	if(ob->query("combat_exp")>30000)
	{
		command("shake");
		command("say 你的武功已经有一定基础了，去找更高级的师傅学吧。"); 
		return 0;
	}
    return 1;	
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("combat_exp")>=30000) return;
	
	command("nod "+ob->query("id"));
	command("say " + RANK_D->query_respect(ob)
				+ "，你可以看我会的功夫"HIY"(cha zhao)"NOR",可以跟我学功夫"HIY"（xue zhao xxx)"NOR"。\n");
	return;
}

int is_apprentice_of() {return 1;}

int ask_kungfu()
{
	object ob=this_player();
	
	if(!ob->query("wuguan/join"))
	{
		command("say 我的功夫概不外传。");
		return 1;
	}
	if(ob->query_temp("wuguan/kungfu"))
	{
		command("say 你想跟我讨教一番？");
		command("consider");
		command("say 接招吧！");
		ob->delete_temp("wuguan/kungfu");
		fight_ob(ob);
		return 1;
	}
	
	command("whisper "+ob->query("id")+
	" 馆主当年是江湖上闻名的千人斩，得到过很多秘籍，你去书房看看，兴许还能找到。");
	ob->set_temp("wuguan/kungfu",1);
	return 1;
}
	