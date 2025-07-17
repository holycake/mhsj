// city/npc/angelus.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("立申", ({ "li shen","li", "shen", "boss"}));
	set("gender", "男性");
	set("age", 42);
	set("long", "他是這家杂货店的老板。\n");
	set("attitude", "friendly");
        set("vendor_goods", ([
			"1":"/clone/misc/sleepbag",
			"2":"/d/city/obj/mabudai",
			"3":"/d/city/npc/obj/baoguo",
			"4":"/d/city/npc/obj/shield",
			"5":"/d/xingxiu/obj/fire",
			"6":"/d/item/obj/chanhs",
			"7":"/clone/misc/wood",
			"8":"/clone/misc/shoeshine",
			"9":"/clone/misc/brush",
			"10":"/d/item/obj/jingtie",
			"11":"/d/nanjing/obj/waist0",
			"12":"/d/nanjing/obj/waist1",
			"13":"/d/nanjing/obj/waist2",
			"14":"/d/nanjing/obj/waist3",
        ]));

	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
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
                        say( "立老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店又来了批新货。\n");
                        break;
                case 1:
                        say( "立老板说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
