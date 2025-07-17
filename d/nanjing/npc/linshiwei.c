#include <ansi.h>

inherit NPC;

string ask_sex();
void greeting(object ob);
int do_remove(object target, object ob);

void create()
{
	seteuid(getuid());
	set_name("林仕薇", ({ "lin shiwei", "lin", "shiwei", "vivi" }));
	set("long", HIM"她愁眉啼妆，出水芙蓉。薄施傅粉鬓边白，淡扫娥眉眼含春。\n"NOR);
	set("nickname", HIC"薇儿"NOR);
	set("gender", "女性");
	set("age", 18);
	set("per", 26);
	set("attitude", "friendly");
	set("limit","nanjing");
	set("shen_type", 1);
	set("kee", 600);
	set("max_kee", 600);
	set("sen", 600);
	set("max_sen", 600);
        set("bodytype", "light");
	set("food", 300);
	set("water", 300);
	set("inquiry", ([
		"自渎"   : (: ask_sex :),
    ]));
	setup();
	carry_object("/d/nanjing/obj/mao_girl"+(5+random(11)))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24));//->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));

    set("chat_chance", 17);
    set("chat_msg", ({
		(: command("wear all") :),
		"薇儿吟道：原上草，露初晞。舊棲新壟兩依依。空床臥聽南窗雨，誰復挑燈夜補衣。\n",
		"薇儿吟道：天寒翠袖薄，日暮倚修竹。\n",
		"薇儿吟道：昔我往矣，楊柳依依。今我來思，雨雪霏霏。\n",
		"薇儿吟道：式微，式微！胡不歸？微君之躬，胡爲乎泥中！\n"
    }));
	seteuid(getuid());
}

void init()
{
	object ob;
	add_action("do_reset", "yao");
	add_action("do_look", "look");

	::init();
	ob = this_player();

//	if( interactive(ob = this_player()) && !is_fighting() ) 
//        {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
//	}
}

string ask_sex()
{
	object me;
	me = this_player();
	if(me->query_temp("look_sex")==1)
	{
		me->delete_temp("look_sex");
		me->set_temp("ask_sex",1);
		message_vision(HIW"\n$n吓了一跳，涨红着脸盯着$N。\n\n"NOR,me, this_object());
		command("look "+(string)me->query("id"));
		message_vision(HIW"\n观察$n的一举一动，也许能从中找出破绽(look)。\n\n"NOR,me, this_object());
		return "奴家可没做那种事情。\n";
	}
	if(me->query_temp("look_sex")==2)
	{
		me->delete_temp("look_sex");
		me->set_temp("ask_sex",2);
		message_vision(HIW"\n$n羞红了脸低头盯着脚尖，担心刚才自己做的事被$N看到。\n"NOR,me, this_object());
		message_vision(HIW"\n看起来$n有点心虚，可以继续观察$p的举动(look)。\n\n"NOR,me, this_object());
		return "奴家真的没做那种事情。\n";
	}
	if(me->query_temp("look_sex")==3)
	{
		me->delete_temp("ask_sex");
		me->set_temp("sex/bao",1);
		message_vision(HIW"\n$n羞红了脸低头盯着脚尖，生怕自己的心事被$N看穿。\n"NOR,me, this_object());
		message_vision(HIW"\n$n眼波一动，有点娇羞地看着$N。\n\n"NOR,me, this_object());
		return "若蒙不弃，可愿一同观书(bao)？\n";
	}
	return "不知道你在胡言乱语些什么？\n";
}

void greeting(object ob)
{
	object me = this_object();
	if (!ob || environment(ob) != environment()) return;
	if(sizeof(filter_array(all_inventory(environment()),(:  $1->is_character() :)))<3)
	{
		message_vision(HIM "$n听见人声慌忙整理好衣物。\n\n" NOR, ob,me);
		command("wear all");
	}
	return;
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

        message_vision("$N将桌子收拾干净。\n", this_object());
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
		if(me->query_temp("ask_sex")==1)
		{
			me->delete_temp("ask_sex");
			me->set_temp("look_sex",2);
			message_vision(HIW"$n感到有点心虚，低下了头。\n\n"NOR,me, this_object());
			message_vision(HIW"继续问问(ask)$n，也许能发现点什么。\n\n"NOR,me, this_object());
			return 0;
		}
		if(me->query_temp("ask_sex")==2)
		{
			me->delete_temp("ask_sex");
			me->set_temp("look_sex",3);
			message_vision(HIW"$N戏谑道：独乐乐不如众乐乐，小娘子方才所为，何不邀请在下？\n\n"NOR,me, this_object());
			message_vision(HIW"继续追问(ask)$n，也许能发现点什么。\n\n"NOR,me, this_object());
			return 0;
		}
		message_vision(HIM "$N看了看你，说道：若是饿(yao)了奴家便去端些吃食来。\n\n" NOR, ob,me);
		return 0;
	}
	return 0;
}

void unconcious()
{
	object target,enemy;
	
	target=this_object();
	target->remove_all_enemy(0);
	target->clear_written();
	message("vision", HIR "\n"+target->name()+"的眼前一黑，接著什么也不知道了....\n\n" NOR, environment(target));
	target->disable_player(" <昏迷不醒>");
	target->delete_temp("sleeped");
	 
	target->set("sen", 0);
	target->set("kee", 0);
	target->set_temp("block_msg/all", 1);
        foreach (enemy in all_inventory(environment()))
        {
        	if(enemy->is_fighting(target))
        	{
	        	message_vision(MAG"$N将$n击昏，打横抱了起来。\n"NOR, enemy,target);
	        	enemy->remove_enemy(target);
	        	target->remove_enemy(enemy);
	        	target->move(enemy);
        	}
        }
}

void die()
{
        unconcious();
}
