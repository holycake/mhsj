inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("简雍", ({ "jian yong","jian", "yong", "boss"}));
        set("title", "箭坊老板");
        set("gender", "男性");
        set("age", 36);
        set("str", 22);
        set("int", 24);
		set("dex", 18);
        set("con", 18);
        set("kee", 500);
        set("max_kee", 500);
        set("sen", 100);
        set("max_sen", 100);
        set("shen", 0);

        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
		set("vendor_goods", ([
		   "1":"/d/nanjing/obj/arrow0",
		   "2":"/d/nanjing/obj/arrow1",
		   "3":"/d/nanjing/obj/arrow2",
        ]));
        setup();
		carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
		carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
		carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
//        set("chat_chance", 1);
//        set("chat_msg", ({
//        	"钱眼开骄傲的说道：本银号已经有上百年的历史，在江南可以说是第一家。\n",
//               "钱眼开笑着说道：在本店存钱无利息，取钱也不收手续费，客官您看着办吧。\n"
//        }));
	seteuid(getuid());
}

void init()
{
	add_action("do_vendor_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "简老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店的箭价廉物美，包您满意。\n");
                        break;
                case 1:
                        say( "简老板说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
