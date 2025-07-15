//Cracked by Roath
// master.c 馆主
// writen by kittt

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("上官云正" , ({ "wuguan master", "shangguan", "yunzheng","master" }) );
	set("gender", "男性");
	set("title", HIC"扬州武馆馆主"NOR);
	set("nickname",HIR"血手无痕--千人斩"NOR);
	set("age", 48);
	set("long",
		"他就是扬州武馆的馆主上官云，当年江湖上号称\n"
		"血手无痕--千人斩。现在江湖上却已很少有人知\n"
		"道他的来历。他穿得普普通通，眉宇之间带着一\n"
		"股英气，让人不由自主产生倾佩之感。\n");
	set("attitude", "friendly");
	set("shen_type", 1);
 
	set("qi",2500); 	
	set("max_qi", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 20000);
	set_skill("force", 140);
	set_skill("strike", 140);
	set_skill("hammer", 100);
	set_skill("kunlun-zhang", 180);
	set_skill("xuantian-wuji", 160);
	set_skill("kunlun-shenfa", 160);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "kunlun-zhang");
	map_skill("force", "xuantian-wuji");
	map_skill("strike", "kunlun-zhang");
	prepare_skill("strike","kunlun-zhang");
	set("inquiry",  ([
		"加入":	"这种小事你去问张总管就行了。",
		"工作" : "具体想干什么，你去找张总管吧，他会安排你的。",
		"练功" : "我这武馆别的没有，练武的地方可不少。",
		"学习" : "这种事情你应该去找文先生。",
        "千人斩" : "那都是我年青时好胜犯下的冤孽，不要再提了。\n",
		]));
	set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("per", 27);
    set_temp("apply/sword",80);
	
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
	object ob=this_player();
	::init();
	
	if (interactive(ob) && !is_fighting() && !wizardp(ob))
	{
		if((int)ob->query("combat_exp") > 20000)
		{
			command("say 咦？你是怎么跑来的？回去回去。 \n");
			command("kick "+ob->query("id"));
			ob->delete("wuguan");
			ob->delete_temp("wuguan");
			command("say 这一招有个名堂，叫作：屁股向上，平沙落雁式。");
			ob->move(CITY_OB("wuguan","wuguangate"));
            tell_room(environment(ob), "只听“哇~~”一声大叫，"+ob->name()+"从武馆前院飞了过来，屁股上还带着一个鞋印！\n", ({ ob }));
		}
		if((int)ob->query_condition("killer"))
		{
			command("say 你竟敢在武馆杀人，还把我千人斩放在眼里么！\n");
            command("consider "+ob->query("id"));
            kill_ob(ob);
		}
	}
}
