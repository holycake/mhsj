//By waiwai@mszj 2000/10/26

inherit NPC;
#include <ansi.h>

void create()
{
       set_name(HIW "小二" NOR, ({"xiao er","er"}));
       set("title",HIM"野郎中医馆"NOR);
       set("gender", "男性");
       set("combat_exp", 50000);
       set("age", 25);
       set("per", 24);
       set("str", 100);
       set("force", 400);
       set("max_force", 200);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);

       setup();

       carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
    ::init();

}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 50000000) 
	{
		tell_object(who, HIB"小二朝你诡异地一笑，然后狠命地推了你一把.....\n
你只觉得一阵的晕旋......\n\n"NOR);
		who->set_temp("rent_paid",1);
		who->move("/d/changan/bx");

		return 1;
	}
	return 0;
}
