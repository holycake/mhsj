#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("陈晶", ({ "chen jing", "chen", "jing", "jingjing" }));
	set("long", HIM"她盈盈秋水卧蚕挂，淡淡春山刘海齐。犹记当年花解语，只今惟有忆相思。\n"NOR);
	set("nickname", WHT"晶晶"NOR);
	set("gender", "女性");
	set("age", 26);
	set("limit","nanjing");
	set("per", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("kee", 600);
	set("max_kee", 600);
	set("sen", 600);
	set("max_sen", 600);
	set("food", 300);
	set("water", 300);
	setup();
    set("chat_chance", 30);
    set("chat_msg", ({
    	(: command("xixi") :),
    	(: command("rose") :),
    	(: random_move :)
    }
    ));
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));

	set("chat_chance", 2);
	seteuid(getuid());
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
    add_action("do_look", "look");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
        	switch(random(12))
        	{
        	case 0: command("wanfu "+(string)ob->query("id"));break;
        	case 1: command("xixi "+(string)ob->query("id"));break;
        	case 2: command("sister "+(string)ob->query("id"));break;
        	case 3: command("smile "+(string)ob->query("id"));break;
        	case 4: command("rose2 "+(string)ob->query("id"));break;
        	case 5: command("boring "+(string)ob->query("id"));break;
        	case 6: command("hehe");break;
        	case 7: command("boring");break;
        	case 8: command("wanfu");break;
        	case 9: command("xixi");break;
        	case 10: command("smile");break;
        	case 11: command("rose2");break;
        	}
	return;
}

int do_look(string arg)
{
   object ob,me;
   ob = this_object();
   me = this_player();
   if( arg && present(arg, environment(me))==ob )	//在下达look命令的me所处的环境下查找id与字符串arg相符合的object，并与object ob进行比较。
   {
	   ob->add("looks",1);
	   if ((int)ob->query("looks")==3)
	   {
		   	   message_vision(HIM "$N有一副漂亮的鹅蛋脸，刘海衬托着一对大眼睛，下挂一副卧蚕。\n\n" NOR, ob,me);
	   	   return 1;	//该函数是最后创建，在最上层。覆盖系统的look函数。如返回0，则执行完该函数后将继续输出系统look函数的返回；如返回1，则仅输出本函数的返回并结束。
	   }
	   if ((int)ob->query("looks")>=6)
	   {
	   	   ob->delete("looks");
		   	   message_vision(HIM "微风吹起$N的裙摆，露出一双小脚。从脚踝到脚面的肌肤裸露在空气中。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$N的脚踝非常纤细。修长、白皙的脚面透着青筋，看起来十分光滑。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$n直勾勾地盯着$N的一对玉足，丝毫没发觉自己的失态。\n\n" NOR, ob,me);
	   	   return 1;
	   }
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
