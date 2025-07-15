// smith.c

#include <ansi.h>

inherit "/inherit/char/smith.c";

void create()
{
	set_name("铁强", ({ "tie qiang", "tie", "qiang", "boss"}));
	set("gender", "男性");
	set("age", 52);
	set("long", "他是这家打铁铺的老板。\n");
	set("attitude", "friendly");
        set("vendor_goods", ({
			"/d/nanjing/obj/bullet",
			"/clone/weapon/changjian",
			"/clone/weapon/changqiang",
			"/d/nanjing/obj/blade_yao",
			"/clone/weapon/hammer",
			"/clone/weapon/tudao",
			"/clone/weapon/dagger",
			"/clone/weapon/tiegun",
			"/clone/weapon/gangdao",
			"/clone/cloth/tiejia",
        }));

	setup();
//	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_repair", "repair");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "铁强笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店打造的铁器可是有口碑的啊。\n");
                        break;
                case 1:
                        say( "铁强说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
