#include <ansi.h>
inherit NPC;

void create()
{
	set_name("傅宗丽", ({"fu zongli", "fu", "yahuan"}) );
	set("title", "伺女");
	set("nickname", "小傅");
	set("gender", "女性" );
	set("per", 27);
	set("age", 17);
	set("long",
	  "这是个身体发育得很好的小女孩。青春、高挑的胴体没有一丝赘肉，紧致的臀部和\n"
	  "修长的双腿在长裙的勾勒下将少女曼妙的身材展现得淋漓尽致，撩拨着男人心中最\n"
	  "原始的欲望。她秀气的脸庞上稚气尚未脱尽，看起来乖巧伶俐的样子。见有人稍微\n"
	  "示意(yao)，便过去加茶倒水。\n");
	set("attitude", "friendly");
	set("kee", 600);
	set("max_kee", 600);
	set("sen", 600);
	set("max_sen", 600);
       set("bodytype", "light");
	set("food", 300);
	set("water", 300);

        setup();
	carry_object("/d/nanjing/obj/mao_girl"+(5+random(11)))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	//carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
    set("chat_chance", 10);
    set("chat_msg", ({
		"小傅乖巧地说道：婢子这就让人准备些点心。\n",
		"小傅笑着说道：这里的酒菜可还合意？\n"
    }));
	seteuid(getuid());
}

void init()
{
        add_action("do_reset", "yao");
        add_action("do_look", "look");
}

void do_yao(string arg)
{
	object ob;
	object me = this_player();
	object where = environment(me);
	ob= new("/d/nanjing/obj/food_yuanxiao");
	ob->move(where);
	ob= new("/d/nanjing/obj/food_songshu");
	ob->move(where);
	ob= new("/d/nanjing/obj/food_doufu");
	ob->move(where);

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
                    ob->is_head() ||
                    ob->query("no_get"))
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

int do_look(string arg)
{
   object ob,me;
   ob = this_object();
   me = this_player();
   if( arg && present(arg, environment(me))==ob )	//在下达look命令的me所处的环境下查找id与字符串arg相符合的object，并与object ob进行比较。
   {
	   ob->add("looks",1);
	   if ((int)ob->query("looks")>=3)
	   {
	   	   ob->delete("looks");
	   	   message_vision(HIM "湘裙拘束着$N仅堪一握的小蛮腰。让人不禁想要搂住她。\n\n" NOR, ob,me);
	   	   message_vision(HIM "裙子在$N的动作之下，不时勾勒出苗条、修长的双腿，撩拨人心。\n\n" NOR, ob,me);
	   	   message_vision(HIM "$n的视线完全被$N的纤腰和双腿吸引住了。\n\n" NOR, ob,me);
	   	   return 1;
	   }
	}
   return 0;
}
