//Cracked by Roath
// sunguanshi.c 工具房管事--老孙
// by yfeng


#include <ansi.h>

inherit NPC;
int give_tool();

void create()
{
	set_name("孙管事", ({ "sun guanshi","guanshi","sun" }));
	set("gender", "男性");
	set("age", 38);
	set("chat_chance", 25);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set("combat_exp", 70000);
	set("shen_type", 1);
	set("inquiry", ([
		"tool": 	(: give_tool:),
		"工具": 	(: give_tool:)
		]));

	setup();
	carry_object(__DIR__"obj/qingcloth")->wear();
}

int give_tool()
{
	object ob=this_player();
	object me=this_object();
	
	return JOB_OB("wuguan")->give_tool(ob,me);
}

void init()
{
	object ob=this_player();
	
	::init();
	
	remove_call_out("greeting");
	call_out("greeting",1,ob);
	return;
}

int accept_object(object ob,object obj)
{
	object me=this_object();
	
	return JOB_OB("wuguan")->accept_tool(me,ob,obj);
}

int greeting(object ob)
{
	if(!ob || (environment(ob)!=environment())) return 0;
         command("say 大家要干活，就找我要工具"+HIY"(ask sun about tool)"NOR+"用完还回来。\n");
}
