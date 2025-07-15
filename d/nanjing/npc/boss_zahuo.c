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
        set("vendor_goods", ({
			"/clone/misc/sleepbag",
			"/d/city/obj/mabudai",
			"/d/city/npc/obj/baoguo",
			"/d/city/npc/obj/shield",
			"/d/xingxiu/obj/fire",
			"/d/item/obj/chanhs",
			"/clone/misc/wood",
			"/clone/misc/shoeshine",
			"/clone/misc/brush",
			"/d/item/obj/jingtie",
			"/d/nanjing/obj/waist0",
			"/d/nanjing/obj/waist1",
			"/d/nanjing/obj/waist2",
			"/d/nanjing/obj/waist3",
        }));

	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
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
                        say( "立老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店又来了批新货。\n");
                        break;
                case 1:
                        say( "立老板说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
