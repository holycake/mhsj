#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("李芬芳", ({ "li fenfang", "li", "fenfang", "fangbao" }));
	set("long", HIM"她手如柔荑，肤如凝脂。嘴角含春双眼绽，玉颜一笑梨渦开。\n"NOR);
	set("nickname", HIR"芳宝"NOR);
	set("gender", "女性");
	set("age", 22);
	set("limit","nanjing");
	set("per", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("kee", 600);
	set("max_kee", 600);
	set("sen", 600);
	set("max_sen", 600);
       set("bodytype", "heavy");
	set("food", 300);
	set("water", 300);

	setup();
    set("chat_chance", 30);
    set("chat_msg", ({
    	(: command("xixi") :),
    	(: command("rose2") :),
    	(: random_move :)
    }
    ));
	carry_object("/d/nanjing/obj/mao_girl"+(5+random(11)))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));

/*	set("chat_chance", 2);
	set("chat_msg", ({
		"陈圆圆抚着古琴说：小妹新近打谱了曲广陵散，请几位姊姊指正。\n",
		"陈圆圆听着琴曲，有些出神。\n",
		"陈圆圆听着琴曲，看着沿岸的景色。\n",
	}) );*/
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
    add_action("do_follow", "follow");
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

int do_follow(string arg)
{
   object ob,me;
   ob = this_object();
   me = this_player();
   if( arg && present(arg, environment(me))==ob )	//在下达look命令的me所处的环境下查找id与字符串arg相符合的object，并与object ob进行比较。
   {
   	   if(random(5)<=3)
   	   {
		   if(me->query("gender") == "女性")
	   	   	   message_vision(HIM "$n看了看$N，调皮地说道：哈哈，来追我呀。\n\n" NOR, me,ob);
	   	   else
	   	   	   message_vision(HIM "$n紧张地看了看$N，快步离开了。\n\n" NOR, me,ob);
	   	   random_move();
   	   }
   	   else{
   	   	   command("hammer "+(string)me->query("id"));
   	   	   message_vision(HIM "$n无奈地看着$N，说道：真是败给你了。干吗老跟着我！\n\n" NOR, me,ob);
//   	   	   command("follow "+(string)me->query("id"));跟隨后需要刪除自動動作，并存在重新激活自動動作的問題。不劃算。
   	   	   command("makelove "+(string)me->query("id"));
   	   }
	}
	return 1;	//返回1则不执行默认的follow动作。
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
