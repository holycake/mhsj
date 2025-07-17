// city/npc/angelus.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("马守诚", ({ "ma shoucheng","ma", "boss"}));
	set("gender", "男性");
	set("age", 42);
	set("long", "他是马市的老板。\n");
	set("attitude", "friendly");
        set("vendor_goods", ([
               "1":"/d/nanjing/obj/horse_benxiao",
               "2":"/d/nanjing/obj/horse_chaoguang",
               "3":"/d/nanjing/obj/horse_chaoying",
               "4":"/d/nanjing/obj/horse_fanyu",
               "5":"/d/nanjing/obj/horse_juedi",
               "6":"/d/nanjing/obj/horse_shengwu",
               "7":"/d/nanjing/obj/horse_xiayi",
               "8":"/d/nanjing/obj/horse_yuhui",
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
                        say( "马老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店又来了批新马。\n");
                        break;
                case 1:
                        say( "马老板说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
