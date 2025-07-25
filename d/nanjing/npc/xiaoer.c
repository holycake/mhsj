// waiter.c

#include <ansi.h>;

inherit NPC;

void create()
{
	set_name("店小二", ({ "xiao er", "xiaoer", "er" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"他是附近一户人家的小儿子，在这家店打工已经有些年头了。\n");
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(7))->wear();
	//carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

string accept_ask(object me, string topic)
{
        switch (random(3))
        {
        case 0:
                return "对不住，本店只收现银。";

        case 1:
                return "你干啥？没看我忙着呢么？";

        default:
               return "这位客人可是要住店？";
        }
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
	case 0:
		say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
			+ "，进来喝杯茶，歇歇腿吧。\n");
		break;
	case 1:
		say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
			+ "，请进请进。\n");
		break;
	}
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 60) 
	{
		tell_object(who, "店小二接过银子，说道：客官请上楼歇息。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
