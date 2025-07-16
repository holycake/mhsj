#include <ansi.h>;
inherit F_VENDOR;
inherit NPC;

varargs protected void create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new("/d/city/obj/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", GRN+"一盘热气腾腾, 香喷喷的"+nmstr+"。\n"+NOR);
        obj->move(environment(this_player()));
}

varargs protected void create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new("/d/city/obj/water");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", YEL+"一杯可口的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(environment(this_player()));
}

varargs protected void create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new("/d/city/obj/wine");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", RED+"一杯醇正的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(environment(this_player()));
}

void create()
{
	set_name("马元敬", ({ "ma yuanjing", "boss", "ma", "yuanjing" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"他是这家饭店的老板。祖上几代人都以经营这家饭馆为生。\n");
	set("attitude", "friendly");
	set("rank_info/respect", "掌柜");
	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(7))->wear();
	//carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	        set("vendor_goods", ([
                "1":"/d/nanjing/obj/food_doufu",
                "2":"/d/nanjing/obj/food_meiren",
                "3":"/d/nanjing/obj/food_shaomai",
                "4":"/d/nanjing/obj/food_songshu",
                "5":"/d/nanjing/obj/food_xia",
                "6":"/d/nanjing/obj/food_yuanxiao",
                "7":"/d/nanjing/obj/food_yumiao",
                "8":"/d/city/obj/jiudai",
        ]));
	seteuid(getuid());
}

void init()
{
	add_action("do_vendor_list", "list");
	add_action("do_buy", "buy");
	add_action("do_reset", "yao");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "马老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来看看？本店的菜可都是每天从市场上买的。\n");
                        break;
                case 1:
                        say( "马老板说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}

void do_yao(string arg)
{
    create_water(HIG"龙井茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
    create_wine(YEL"绍兴黄酒"NOR, ({ "wine" }), HIY"象牙杯"NOR );
    create_food(YEL"香酥花生"NOR,({"peanut"}) );
    message_vision(HIR"$N急忙端上几小碟菜。\n"NOR, this_object());
    return;
}

void do_clear()
{
        object ob;
/*        int n;

        n = 0;*/
        foreach (ob in all_inventory(environment()))
        {
                if (ob->is_character() ||
                    ob->is_head()/* ||
                    ob->query("no_get")*/)
                        continue;
                destruct(ob);
                //n++;
        }

        message_vision("$N将桌子上的一片狼籍收走。\n", this_object());
        return;
}

int do_reset()
{
	remove_call_out("do_clear");
	remove_call_out("do_yao");
	call_out("do_clear",1);
	call_out("do_yao", 5);
	message_vision("$N说道：请稍等，马上就来。\n", this_object());
	return 1;
}
