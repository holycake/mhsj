// city/npc/angelus.c
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("苏柳", ({ "shu liu", "su", "liu", "suliu", "boss"}));
	set("gender", "女性");
	set("age", 28);
	set("long", "她是这家梳篦老铺老板的女儿。\n");
	set("attitude", "friendly");
        set("vendor_goods", ({
			"/d/nanjing/obj/waist0",
			"/d/nanjing/obj/waist1",
			"/d/nanjing/obj/waist2",
			"/d/nanjing/obj/waist3",
			"/d/nanjing/obj/mao_girl0",
			"/d/nanjing/obj/mao_girl1",
			"/d/nanjing/obj/mao_girl2",
			"/d/nanjing/obj/mao_girl3",
			"/d/nanjing/obj/mao_girl4",
			"/d/nanjing/obj/mao_girl5",
			"/d/nanjing/obj/mao_girl6",
			"/d/nanjing/obj/mao_girl7",
			"/d/nanjing/obj/mao_girl8",
			"/d/nanjing/obj/mao_girl9",
			"/d/nanjing/obj/mao_girl10",
			"/d/nanjing/obj/mao_girl11",
			"/d/nanjing/obj/mao_girl12",
			"/d/nanjing/obj/mao_girl13",
			"/d/nanjing/obj/mao_girl14",
			"/d/nanjing/obj/mao_girl15",
			"/d/nanjing/obj/mao_min0",
			"/d/nanjing/obj/mao_min1",
			"/d/nanjing/obj/mao_min2",
			"/d/nanjing/obj/mao_min3",
			"/d/nanjing/obj/mao_min4",
			"/d/nanjing/obj/mao_min5",
			"/d/nanjing/obj/mao_min6",
			"/d/nanjing/obj/mao_min7",
			"/d/nanjing/obj/mao_min8",
			"/d/nanjing/obj/mao_min9",
			"/d/nanjing/obj/mao_min10",
			"/d/nanjing/obj/mao_nv0",
			"/d/nanjing/obj/mao_nv1",
			"/d/nanjing/obj/mao_nv2",
			"/d/nanjing/obj/mao_nv3",
			"/d/nanjing/obj/mao_nv4",
			"/d/nanjing/obj/mao_nv5",
			"/d/nanjing/obj/mao_nv6",
			"/d/nanjing/obj/mao_nv7",
			"/d/nanjing/obj/mao_nv8",
			"/d/nanjing/obj/mao_nv9",
			"/d/nanjing/obj/mao_nv10",
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
                        say( "苏柳笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店的首饰应有尽有。\n");
                        break;
                case 1:
                        say( "苏柳说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
