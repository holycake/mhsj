// city/npc/angelus.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("刘颀", ({ "liu qi", "liu", "qi", "liuqi", "boss"}));
	set("gender", "女性");
	set("age", 32);
	set("long", "她是这家织锦坊的老板娘。\n");
	set("attitude", "friendly");
        set("vendor_goods", ({
        	"/d/nanjing/obj/cloth_nei",
			"/d/nanjing/obj/cloth_nv0",
			"/d/nanjing/obj/cloth_nv1",
			"/d/nanjing/obj/cloth_nv2",
			"/d/nanjing/obj/cloth_nv3",
			"/d/nanjing/obj/cloth_nv4",
			"/d/nanjing/obj/cloth_nv5",
			"/d/nanjing/obj/cloth_nv6",
			"/d/nanjing/obj/cloth_nv7",
			"/d/nanjing/obj/cloth_nv8",
			"/d/nanjing/obj/cloth_nv9",
			"/d/nanjing/obj/cloth_nv10",
			"/d/nanjing/obj/cloth_nv11",
			"/d/nanjing/obj/cloth_nv12",
			"/d/nanjing/obj/cloth_nv13",
			"/d/nanjing/obj/cloth_nv14",
			"/d/nanjing/obj/cloth_nv15",
			"/d/nanjing/obj/cloth_shi0",
			"/d/nanjing/obj/cloth_shi1",
			"/d/nanjing/obj/cloth_shi2",
			"/d/nanjing/obj/cloth_shi3",
			"/d/nanjing/obj/cloth_min0",
			"/d/nanjing/obj/cloth_min1",
			"/d/nanjing/obj/cloth_min2",
			"/d/nanjing/obj/cloth_min3",
			"/d/nanjing/obj/cloth_min4",
			"/d/nanjing/obj/cloth_min5",
			"/d/nanjing/obj/cloth_min6",
			"/d/nanjing/obj/skirt_nv0",
			"/d/nanjing/obj/skirt_nv1",
			"/d/nanjing/obj/skirt_nv2",
			"/d/nanjing/obj/skirt_nv3",
			"/d/nanjing/obj/skirt_nv4",
			"/d/nanjing/obj/skirt_nv5",
			"/d/nanjing/obj/skirt_nv6",
			"/d/nanjing/obj/skirt_nv7",
			"/d/nanjing/obj/skirt_nv8",
			"/d/nanjing/obj/skirt_nv9",
			"/d/nanjing/obj/skirt_nv10",
			"/d/nanjing/obj/skirt_nv11",
			"/d/nanjing/obj/skirt_nv12",
			"/d/nanjing/obj/skirt_nv13",
			"/d/nanjing/obj/skirt_nv14",
			"/d/nanjing/obj/skirt_nv15",
			"/d/nanjing/obj/skirt_nv16",
			"/d/nanjing/obj/skirt_nv17",
			"/d/nanjing/obj/skirt_nv18",
			"/d/nanjing/obj/skirt_nv19",
			"/d/nanjing/obj/skirt_nv20",
			"/d/nanjing/obj/skirt_nv21",
			"/d/nanjing/obj/skirt_nv22",
			"/d/nanjing/obj/skirt_nv23",
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
                        say( "刘颀笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店的衣服保您满意。\n");
                        break;
                case 1:
                        say( "刘颀说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
