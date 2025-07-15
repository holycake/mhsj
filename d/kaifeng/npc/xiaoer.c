// waiter.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
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
	if (!ob->query_temp("welcome100") || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
tell_object(ob,HIY"店小二笑咪咪地说道：这位"+RANK_D->query_respect(ob)+"，欢迎来到"GRN"风起云涌II。"HIY"

    如果你有什么不明白的，可以问老玩家。缺钱花，也可以请老玩家
帮你暂渡难关。大侠们都会乐于助人的。当然你也可以用"HIC"help"HIY"来获得我
们给您的帮助。
    你在"HIC"help"HIY"中能看到很多帮助项目。
    这里的故事和情节，谜语的基本依据是金庸的十五本小说。如果你
对故事不太记得了或想了解多些可以用"HIC"help intro"HIY"这个帮助项。如果你
从没玩过 MUD游戏，那就先看看"HIC"help newbie"HIY"来新手上路吧。"HIC"help cmds"HIY"
是这里所有玩家都能用的命令。想认识一下这里的地图就"HIC"help map"HIY"，里
面有很多项目的，你可以选择地图项目"HIC"help map_all"HIY"看到整个游戏的地
图。而"HIC"help map_yz "HIY"就是你现在呆的城市的地图。当然最重要的是向老
玩家请教，这就一定要会使用"HIC"chat"HIY"这个命令啦。这里的帮助文件也因为
我们的工作而更新，多多留意哦。客店往西，南，西，西，南就到武馆
了，叛师在这里会吃亏的，所以没想好拜哪个门派就先去武馆学。扬州
的武庙是信息中心，常去看看那里的公告，最新的消息一定最早出现在
那里。
	
"NOR);
}
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
	
	if (ob->query("money_id") && ob->value() >= 5000) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
