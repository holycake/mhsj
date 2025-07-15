// city/npc/angelus.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("李二娘", ({ "li erniang","li", "erniang", "boss"}));
	set("gender", "女性");
	set("age", 42);
	set("long", "她是這家果蔬店的老板。\n");
	set("attitude", "friendly");
        set("vendor_goods", ({
			"/d/city/npc/obj/peanut",
			"/d/city/obj/rrose",
			"/d/city/obj/yrose",
			"/clone/game/fruit",
			"/clone/herb/haitang",
			"/d/beijing/obj/luobo",
			"/d/beijing/obj/huluobo",
			"/d/beijing/obj/baicai",
			"/d/beijing/obj/dacong",
			"/d/beijing/obj/tudou",
	        	"/d/changan/npc/obj/pingguo",
	        	"/d/changan/npc/obj/hamigua",
	        	"/d/changan/npc/obj/juzi",
                	"/d/wudang/obj/mitao",
                	"/d/xiakedao/obj/mangguo",
        }));

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "二娘笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店卖的蔬果可新鲜了。\n");
                        break;
                case 1:
                        say( "二娘说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
