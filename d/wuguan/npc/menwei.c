//Cracked by Roath
// by dubei
inherit NPC;
#include <ansi.h>
void create()
{
	int age = 20 + random(20);
	set_name("武馆门卫", ({ "men wei", "menwei", "wei" }));
	set("gender", "男性");
	set("age", age);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set("apply/attack", 30);
	set("apply/defense", 30);
	set("apply/damage", 35);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	add_money("silver", 3+age/10);
	carry_object(__DIR__"obj/cloth")->wear();
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
	
void greeting(object ob)
{
	if( !ob || environment(ob) != environment()) return;
	if((ob->query("combat_exp") < 20000) && !ob->query("wuguan/join")) 
		command("say 我扬州武馆广招贤才，这位" + RANK_D->query_respect(ob)+"何不一试？\n");
	if(ob->query("combat_exp") > 20000  && ob->query("combat_exp") < 80000 )
	{
		command("say 蒙古目前正在攻打襄阳，宋军现在正需人才，这位" + RANK_D->query_respect(ob)+"武功已有根基，何不去为国效力？\n");
		if (ob->query("wuguan/join")) ob->delete("wuguan");
		message_vision(CYN"$N微微一笑，朗声说道：多谢壮士相告，我这就前去看看。说罢，抖擞精神，准备步出武馆。\n"NOR, ob);
	}
	if ( ob->query("combat_exp") > 80000)
	{
		command("hmm "+ob->query("id"));
		command("say 这里只收留江湖新手，你到这里有什么不轨企图！");
	}
	return;
}
