// tuying-zunzhe.c...weiqi, 97.09.15.

#include <ansi.h>

inherit NPC;
string expell_me(object me);
void create()
{
	set_name("秃鹰尊者", ({"tuying zunzhe", "tuying", "zunzhe"}));
	set("title", "明王护法");
	set("gender", "男性" );
	set("age", 53);
	set("per", 112);//no rongmao description.

	set("long", "大鹏明王座下四护法尊者之一。额头高耸，一看就知道功力深厚。\n");
	set("class", "yaomo");
	set("combat_exp", 500000);
	set("daoxing", 400000);

	set("attitude", "peaceful");
	create_family("大雪山", 2, "弟子");
	set_skill("unarmed",190);
	set_skill("yingzhaogong", 230);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("bingpo-blade", 180);
	set_skill("force", 200);   
	set_skill("ningxie-force", 200);
	set_skill("literate", 180);
	set_skill("spells", 200);
	set_skill("dengxian-dafa", 230);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "yingzhaogong");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	set("max_kee", 800);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1000);
	set("max_mana", 500);	
	set("force_factor", 50);
	set("mana_factor", 25);

        set("eff_dx", -120000);
        set("nkgain", 300);

	set("inquiry", ([
		"leave": (: expell_me :),
		"name": "嘿嘿！\n",
		"here": "多看少说！\n",
	]) );


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	//carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="大雪山" ){
		if( (int)ob->query("family/generation") < 2  ){
			command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
		}
		else if( (int)ob->query("family/generation") ==2  ){
			command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣大爷我了！\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command(":D");
			command("say 你这个" + RANK_D->query_rude(ob) + "早就该来拜我为师！你那个破师父什么都不懂...\n");
			command("recruit " + ob->query("id") );
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 150000 ){
				command(":D ");
				command("say 好，到我这里来学艺，别的不说，保证" + RANK_D->query_respect(ob) + "你一双手练得是生裂虎豹！\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say 你还是找鹦鹉，乌鸦他们先练着吧。\n");
			}
		}
	}

	else{
		command("hmm");
		command("say 这位" + RANK_D->query_respect(ob) + "，没有推荐人我可不能收你。\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

string expell_me(object me)
{       
	int stage, bonus;
	me=this_player();

	stage=(int)me->query("nx-force_bonus");
	if( stage < 2 ) bonus = 0;
	else if( stage == 2 ) bonus = 100;
	else if( stage == 3 ) bonus = (2+3)*50;
	else if( stage == 4 ) bonus = (2+3+4)*50;
	else if( stage == 5 ) bonus = (2+3+4+5)*50;
	else if( stage == 6 ) bonus = (2+3+4+5+6)*50;
	else if( stage == 7 ) bonus = (2+3+4+5+6+7)*50;
	else if( stage == 8 ) bonus = (2+3+4+5+6+7+8)*50;
	else                  bonus = (2+3+4+5+6+7+8+9)*50;


	if((string)me->query("family/family_name")=="大雪山") {
		message_vision("秃鹰尊者面色一沉，道：现在正是本门危急之时...\n", me);
		me->set_temp("xs_betray", 1);
		message_vision("秃鹰尊者阴森森地盯着$N，接着道：你真的想逃(true)？\n", me);
		if ( bonus> 0 )
		{
			message_vision("秃鹰尊者顿了一下：还有，你从本门冰谷凝血功得到好处可别想带走：共是内力"+chinese_number(bonus)+"点。\n", me);
			me->set_temp("xs_neili_penalty", bonus);
		}
		return ("嘿嘿！\n");
	}
	return ("问什么问！自己想去！\n");
}

void init()
{
	add_action("do_true", "true");
}

int do_true(string arg)
{
	int force_after = 0;
        if((string)this_player()->query("family/family_name")=="大雪山") {
	if(this_player()->query_temp("xs_betray")) {
		message_vision("$N答道：弟子讲的真心话！\n\n", this_player());
		message_vision("秃鹰尊者叹了口气道：好！你从此便是本门的敌人了！\n", this_player());
		this_player()->add("betray/xueshan", 1);
		this_player()->add("betray/count", 1);

		this_player()->set("combat_exp", this_player()->query("combat_exp")/100*80);
		this_player()->set("daoxing", this_player()->query("daoxing")/100*80);
		// xintai 12/24/2001
		this_player()->delete_skill("ningxie-force");

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("nx-force_bonus");
		// added by xintai 12/24/2001 让回来的xueshan弟子可以继续享用ningxie-force的好处
		this_player()->add("betray/count", 1);
		this_player()->add("betray/xueshan", 1);
		this_player()->set("title", "普通百姓");
		this_player()->delete_temp("xs_betray");

		force_after = (int)this_player()->query("max_force")-this_player()->query_temp("xs_neili_penalty");
		if(force_after < 0) force_after = 0;// 12/24/2001 xintai 避免出现负的内力。
		this_player()->set("max_force", 
			force_after);

		this_player()->delete_temp("xs_neili_penalty");
		this_player()->save();
		message_vision("秃鹰尊者一脚踢中$N的屁股，$N腾云驾雾般飞了出去...\n", this_player());
		this_player()->move("/d/xueshan/binggu");
		tell_room( environment(this_player()),"只听劈啪！一声，一个人从空中飞过来，死猪般地摔在地上。\n", ({this_player()}));
		return 1;
	}
	return 0;
}
                else return notify_fail("什么？\n");
}

