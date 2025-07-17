#include <ansi.h>

inherit NPC;

void greeting(object ob);
string ask_hire();
int accept_object(object who, object ob);

void create()
{
	seteuid(getuid());
	set_name("田川希子", ({ "tianchuan xizi", "tianchuan", "xizi","xi", "nancy", "maomao" }));
	set("long", HIM"她鬓垂香颈，领如蝤蛴。削肩细腰，袅袅娉娉。一阵轻风笑语过，任它柳絮转飘零。\n"NOR);
	set("nickname", HIM"猫猫"NOR);
	set("gender", "女性");
	set("limit","nanjing");
	set("age", 23);
	set("per", 28);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("kee", 600);
	set("max_kee", 600);
        set("bodytype", "light");	
	set("sen", 600);
	set("max_sen", 600);
	set("food", 300);
	set("water", 300);

        set("inquiry", ([
                "丫鬟"   : (: ask_hire :),
                "丫环"   : (: ask_hire :),
                "yahuan"   : (: ask_hire :),
        ]));
	setup();
	carry_object("/d/nanjing/obj/mao_girl"+(5+random(11)))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));

    set("chat_chance", 3);
    set("chat_msg", ({
    	(: command("xixi") :),
    	(: command("rose") :)
//    	(: random_move :)
    }
    ));
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

string ask_hire()
{
        object me;
        me = this_player();
	 message_vision("\n$n看着$N说道：若是身边少个服侍的人，奴家可以代为寻找。\n\n",me, this_object());
        return "卖身为奴的女孩多是家境不好或者家里有了难处的，只要给我三十两银子就能找来。\n普通人家的姑娘一般不爱做这种生计，得花二百两纹银。\n若是想找个精通诗词歌赋、心思细腻，可心点的，那都是家里落难的富贵人家的姑娘，恐怕得花五百金人家才肯答应。\n";
}

int accept_object(object who, object ob)
{
        int amount, money_limit, per;
        object me;

        me = this_player();

        if (! ob->query("money_id"))
            return notify_fail("希子俏皮地说：奴家只认钱。\n");

		if (who->is_busy())
		return notify_fail("你还是等有空了再说吧！\n");

        if (this_object()->is_fighting())
			return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
//
//		if (ob->value() !=3000 || ob->value() !=20000 || ob->value() !=5000000 )
//		{
//	        message_vision(sprintf("$N说道：您给的太多了。\n"),this_object());
//	        return 0;
//		}

        amount=(int)ob->query_amount();
        money_limit=ob->query("base_value") * amount;
        switch(money_limit)
        {
		case 3000: per = 26+random(8);break;
		case 20000: per = 35+random(26);break;
		case 5000000: per = 65+random(26);break;
    	 }

        ob = new(CLASS_D("generate") + "/girl");

        ob->set_temp("renter", this_object());
//        NPC_D->init_npc_skill(ob, lvl);
        ob->autoload("丫鬟||ya huan||"+per+"||",me);	//设置丫鬟的主人和名字、per值

        return 1;
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
