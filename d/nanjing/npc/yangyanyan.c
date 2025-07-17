#include <ansi.h>

inherit NPC;

string ask_chest();
string ask_milk();
string ask_massage();
string ask_drink();
int accept_object(object who, object ob);

void create()
{
        set_name("杨妍妍", ({"yang yanyan", "yang", "yanyan"}));
        set("long", HIM"她纤腰束湘裙，耳缀明月铛。玉容寂寞冷，皓腕衬香腮。\n"NOR);
        set("title", "帐房");
        set("nickname", HIC"妍妍"NOR);
        set("gender", "女性");
        set("age", 24);
        set("str", 22);
        set("int", 24);
        set("per", 29);
	set("limit","nanjing");
		set("dex", 18);
        set("con", 18);
		set("kee", 600);
		set("max_kee", 600);
		set("sen", 600);
		set("max_sen", 600);
		set("food", 300);
		set("water", 300);
        set("shen", 1);
        set("bodytype", "light");

        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        set("inquiry", ([
                "揉胸"   : (: ask_chest :),
                "chest"   : (: ask_chest :),
                "奶水"    : (: ask_milk :),
                "milk"    : (: ask_milk :),
                "推拿"    : (: ask_massage :),
                "massage"    : (: ask_massage :),
                "tuina"    : (: ask_massage :),
                "喝奶"    : (: ask_drink :),
                "drink"    : (: ask_drink :),
        ]));
        setup();
		carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
		carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
		carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
		carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
		carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
		add_money("silver",3+random(7));
        set("chat_chance", 7);
        set("chat_msg", ({
		(: command("wear all") :),
		"妍妍趁无人注意揉了揉胸，似乎胸部涨得难受。\n",
		"妍妍喃喃说道：奶水如此之多，却无用处。\n",
		"妍妍笑着说道：奴家正要去钱庄，若需存款，直接给奴家便是。\n"
        }));
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
	 add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        add_action("do_give", "give");
    	add_action("do_look", "look");
}

void greeting(object ob)
{
	command("wear all");
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

string ask_chest()
{
        object me;
        me = this_player();
		message_vision("\n$n看着$N，无奈地叹了口气。\n",me, this_object());
        return "最近奶水太多，胸部涨得厉害。看来得空要去推拿一下了。\n";
}

string ask_milk()
{
        object me;
        me = this_player();
		message_vision("\n$n附在$N的耳边悄声说着话。\n$p吐气如兰，$N不由地从耳朵一直痒到心里。\n",me, this_object());
        return "多余的奶水奴家只能倒掉。\n";
}

string ask_drink()
{
        object me;
        object ob;
	    ob = this_object();
        me = this_player();
		message_vision("\n$n羞红了脸，双手护住胸部。\n",me, ob);
        return "奴家可是正经人家，才做不出那丢人的事来。\n";	//return中调用玩家和NPC的名字需要用me->name()
}

string ask_massage()
{
        object me;

        me = this_player();
        if (me->query_temp("sex/massage"))
                return "那便有劳了(massage)。\n";

		message_vision("\n$n高兴地看着$N问道：你愿为奴家推拿？\n",me, this_object());
		me->set_temp("sex/massage", 1);
        return "那便有劳了(massage)。\n";
}

int accept_object(object who, object ob)
{
        int amount;

        if (! ob->query("money_id"))
            return notify_fail("妍妍俏皮地说：奴家只认钱。\n");

		if (who->is_busy())
		return notify_fail("你还是等有空了再说吧！\n");

        if (this_object()->is_fighting())
			return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

		if (ob->value()<60)
		{
	        message_vision(sprintf("$N撒娇到：这点钱奴家才不要特意跑去钱庄呢。\n"),this_object());
	        return 0;
		}

		amount=(int)ob->query_amount();
        // deposit it
        who->start_busy(1);

		/*if (who->query("balance") >= 1000000000)
			return notify_fail("你的存款已达上限。\n");*/

        who->add("balance", ob->query("base_value") * amount);
        //ob->add_amount(-amount);
        message_vision(sprintf("$N说道：一共是%s%s%s，奴家一会便送去钱庄。\n",
        chinese_number(amount), ob->query("base_unit"),
        ob->query("name")), this_object());
        return 1;
}

int do_look(string arg)
{
   object ob,me;
   ob = this_object();
   me = this_player();
   if( arg && present(arg, environment(me))==ob )	//在下达look命令的me所处的环境下查找id与字符串arg相符合的object，并与object ob进行比较。
   {
	   ob->add_temp("looks",1);
	   if ((int)ob->query_temp("looks")==2)
	   {
		   	   message_vision(HIM "$N坐在椅子上，薄薄的湘裙被压在身下。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$n的目光马上被吸引了过去，不住地往$N的的双腿偷瞧。\n\n" NOR, ob,me);
	   	   return 1;	//该函数是最后创建，在最上层。覆盖系统的look函数。如返回0，则执行完该函数后将继续输出系统look函数的返回；如返回1，则仅输出本函数的返回并结束。
	   }
	   if ((int)ob->query_temp("looks")==3)
	   {
		   	   message_vision(HIM "$N的一双玉腿被湘裙紧紧地束缚着，勾勒出修长、匀称的线条。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$n目不转睛地看着$N的玉腿。恨不得上前抚摸一把。\n\n" NOR, ob,me);
	   	   return 1;
	   }
	   if ((int)ob->query_temp("looks")>=4)
	   {
	   	   ob->delete_temp("looks");
		   	   message_vision(HIM "$N的两脚不经意地动了下。透出万种风情。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$n痴痴地盯着$N的双腿，想要一亲芳泽。\n\n" NOR, ob,me);
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
	        	target->move(enemy);
        	}
        }
}

void die()
{
        unconcious();
}
