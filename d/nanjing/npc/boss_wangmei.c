#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("王眉儿", ({ "wang meier","wang", "boss", "meier", "mei"}));
	set("title","宝宝");
	set("gender", "女性");
	set("age", 22);
	set("per", 29);
	set("long", "她是这家店的女掌柜。虽不能说是国色天香，倒也生得皮肤白净，一副桃花眼甚是撩人。\n");
	set("attitude", "friendly");

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();

	set("chat_chance", 20);
	set("chat_msg", ({
		HIM"眉儿说道：茅香，花、苗、叶可煮作浴汤，辟邪气，令人身香。\n"NOR,
		HIM"眉儿说道：夏月宜用五枝汤洗浴，浴讫，以香粉傅身。\n能驱瘴毒，疏风气，滋血脉，且免汗湿阴处，使皮肤燥痒。\n"NOR,
		HIM"眉儿说道：这傅身香粉，用粟米或葛粉作粉一斤。加青木香、麻黄根、炒香附子、\n甘松、藿香、零陵香，以上各二两，捣罗为末，和粉拌匀，作稀绢袋盛之，浴后扑身。\n"NOR,
		HIM"眉儿说道：这是当年杨贵妃所用匀面“润鬓二色膏油”，用白胭脂花、白杏仁心、梨汁\n、白龙脑相熬合，用以调粉匀面，使皮肤白晰光润。\n"NOR,
		HIM"眉儿说道：这兰花名赛兰香，其香气馥烈，戴于发髻上，可以香闻十步，经月不散。\n"NOR,
		HIM"眉儿说道：这汤丸系用熏草杂合各种香料，作香汤，令人身香。\n"NOR,
	}) );
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "眉儿笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看吧？\n");
                        break;
                case 1:
                        say( "眉儿说道：客人是要香料还是脂粉？\n");
                        break;
        }
}
