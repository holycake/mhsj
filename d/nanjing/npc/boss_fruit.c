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
        set("vendor_goods", ([
		"1":"/d/city/npc/obj/peanut",
		"2":"/d/city/obj/rrose",
		"3":"/d/city/obj/yrose",
		"4":"/clone/game/fruit",
		"5":"/clone/herb/haitang",
		"6":"/d/beijing/obj/luobo",
		"7":"/d/beijing/obj/huluobo",
		"8":"/d/beijing/obj/baicai",
		"9":"/d/beijing/obj/dacong",
		"10":"/d/beijing/obj/tudou",
		"11":"/d/changan/npc/obj/pingguo",
		"12":"/d/changan/npc/obj/hamigua",
		"13":"/d/changan/npc/obj/juzi",
		"14":"/d/wudang/obj/mitao",
		"15":"/d/xiakedao/obj/mangguo",
        ]));

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
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
