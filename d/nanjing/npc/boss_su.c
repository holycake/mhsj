// city/npc/angelus.c
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("苏柳", ({ "su liu", "su", "liu", "suliu", "boss"}));
	set("gender", "女性");
	set("age", 28);
	set("long", "她是这家梳篦老铺老板的女儿。\n");
	set("attitude", "friendly");
        set("vendor_goods", ([
			"1":"/d/nanjing/obj/waist0",
			"2":"/d/nanjing/obj/waist1",
			"3":"/d/nanjing/obj/waist2",
			"4":"/d/nanjing/obj/waist3",
			"5":"/d/nanjing/obj/mao_girl0",
			"6":"/d/nanjing/obj/mao_girl1",
			"7":"/d/nanjing/obj/mao_girl2",
			"8":"/d/nanjing/obj/mao_girl3",
			"9":"/d/nanjing/obj/mao_girl4",
			"10":"/d/nanjing/obj/mao_girl5",
			"11":"/d/nanjing/obj/mao_girl6",
			"12":"/d/nanjing/obj/mao_girl7",
			"13":"/d/nanjing/obj/mao_girl8",
			"14":"/d/nanjing/obj/mao_girl9",
			"15":"/d/nanjing/obj/mao_girl10",
			"16":"/d/nanjing/obj/mao_girl11",
			"17":"/d/nanjing/obj/mao_girl12",
			"18":"/d/nanjing/obj/mao_girl13",
			"19":"/d/nanjing/obj/mao_girl14",
			"20":"/d/nanjing/obj/mao_girl15",
			"21":"/d/nanjing/obj/mao_min0",
			"22":"/d/nanjing/obj/mao_min1",
			"23":"/d/nanjing/obj/mao_min2",
			"24":"/d/nanjing/obj/mao_min3",
			"25":"/d/nanjing/obj/mao_min4",
			"26":"/d/nanjing/obj/mao_min5",
			"27":"/d/nanjing/obj/mao_min6",
			"28":"/d/nanjing/obj/mao_min7",
			"29":"/d/nanjing/obj/mao_min8",
			"30":"/d/nanjing/obj/mao_min9",
			"31":"/d/nanjing/obj/mao_min10",
			"32":"/d/nanjing/obj/mao_nv0",
			"33":"/d/nanjing/obj/mao_nv1",
			"34":"/d/nanjing/obj/mao_nv2",
			"35":"/d/nanjing/obj/mao_nv3",
			"36":"/d/nanjing/obj/mao_nv4",
			"37":"/d/nanjing/obj/mao_nv5",
			"38":"/d/nanjing/obj/mao_nv6",
			"39":"/d/nanjing/obj/mao_nv7",
			"40":"/d/nanjing/obj/mao_nv8",
			"41":"/d/nanjing/obj/mao_nv9",
			"42":"/d/nanjing/obj/mao_nv10",
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
                        say( "苏柳笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店的首饰应有尽有。\n");
                        break;
                case 1:
                        say( "苏柳说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
