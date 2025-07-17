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
        set("vendor_goods", ([
		"1":"/d/nanjing/obj/cloth_nei",
		"2":"/d/nanjing/obj/cloth_nv0",
		"3":"/d/nanjing/obj/cloth_nv1",
		"4":"/d/nanjing/obj/cloth_nv2",
		"5":"/d/nanjing/obj/cloth_nv3",
		"6":"/d/nanjing/obj/cloth_nv4",
		"7":"/d/nanjing/obj/cloth_nv5",
		"8":"/d/nanjing/obj/cloth_nv6",
		"9":"/d/nanjing/obj/cloth_nv7",
		"10":"/d/nanjing/obj/cloth_nv8",
		"11":"/d/nanjing/obj/cloth_nv9",
		"12":"/d/nanjing/obj/cloth_nv10",
		"13":"/d/nanjing/obj/cloth_nv11",
		"14":"/d/nanjing/obj/cloth_nv12",
		"15":"/d/nanjing/obj/cloth_nv13",
		"16":"/d/nanjing/obj/cloth_nv14",
		"17":"/d/nanjing/obj/cloth_nv15",
		"18":"/d/nanjing/obj/cloth_shi0",
		"19":"/d/nanjing/obj/cloth_shi1",
		"20":"/d/nanjing/obj/cloth_shi2",
		"21":"/d/nanjing/obj/cloth_shi3",
		"22":"/d/nanjing/obj/cloth_min0",
		"23":"/d/nanjing/obj/cloth_min1",
		"24":"/d/nanjing/obj/cloth_min2",
		"25":"/d/nanjing/obj/cloth_min3",
		"26":"/d/nanjing/obj/cloth_min4",
		"27":"/d/nanjing/obj/cloth_min5",
		"28":"/d/nanjing/obj/cloth_min6",
		"29":"/d/nanjing/obj/skirt_nv0",
		"30":"/d/nanjing/obj/skirt_nv1",
		"31":"/d/nanjing/obj/skirt_nv2",
		"32":"/d/nanjing/obj/skirt_nv3",
		"33":"/d/nanjing/obj/skirt_nv4",
		"34":"/d/nanjing/obj/skirt_nv5",
		"35":"/d/nanjing/obj/skirt_nv6",
		"36":"/d/nanjing/obj/skirt_nv7",
		"37":"/d/nanjing/obj/skirt_nv8",
		"38":"/d/nanjing/obj/skirt_nv9",
		"39":"/d/nanjing/obj/skirt_nv10",
		"40":"/d/nanjing/obj/skirt_nv11",
		"41":"/d/nanjing/obj/skirt_nv12",
		"42":"/d/nanjing/obj/skirt_nv13",
		"43":"/d/nanjing/obj/skirt_nv14",
		"44":"/d/nanjing/obj/skirt_nv15",
		"45":"/d/nanjing/obj/skirt_nv16",
		"46":"/d/nanjing/obj/skirt_nv17",
		"47":"/d/nanjing/obj/skirt_nv18",
		"48":"/d/nanjing/obj/skirt_nv19",
		"49":"/d/nanjing/obj/skirt_nv20",
		"50":"/d/nanjing/obj/skirt_nv21",
		"51":"/d/nanjing/obj/skirt_nv22",
		"52":"/d/nanjing/obj/skirt_nv23",
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
                        say( "刘颀笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店的衣服保您满意。\n");
                        break;
                case 1:
                        say( "刘颀说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
