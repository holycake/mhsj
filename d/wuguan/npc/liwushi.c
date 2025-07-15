//Cracked by Roath
// liwushi.c

inherit NPC;

#include <ansi.h>
void create()
{
        set_name("李武师", ({ "li wushi", "li","wushi" }));
        set("long", "一名武馆内的教头，专门负责教新手空手武功。\n");
        set("gender", "男性");
        set("age", 42);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("sword",80);
        set_skill("stick", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

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
				+ "，你可以看我会的功夫"HIY"(cha li)"NOR",可以跟我学功夫"HIY"（xue li xxx)"NOR"。\n");
	return;
}

int is_apprentice_of() {return 1;}
