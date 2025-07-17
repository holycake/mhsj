// smith.c

#include <ansi.h>

inherit "/feature/smith";

void create()
{
	set_name("铁强", ({ "tie qiang", "tie", "qiang", "boss"}));
	set("gender", "男性");
	set("age", 52);
	set("long", "他是这家打铁铺的老板。\n");
	set("attitude", "friendly");
        set("vendor_goods", ([
		"1":"/clone/armor/fenghuang",
		"2":"/clone/armor/fork",
		"3":"/clone/armor/whip",
		"4":"/clone/armor/hammer",
		"5":"/clone/armor/bang",
		"6":"/clone/armor/blade",
		"7":"/clone/armor/sword",
		"8":"/clone/armor/staff",
		"9":"/clone/armor/spear",
		"10":"/clone/armor/mace",
		"11":"/d/nanjing/obj/blade_yao",
        ]));

	setup();
//	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
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
