// kongque-gongzhu.c...weiqi, 97.09.15.

#include <ansi.h>
inherit NPC;

string get_ice(object me);
void do_drop(object ob);

void create()
{
          set_name(HIG"孔雀公主"NOR, ({"kongque gongzhu", "kongque", "gongzhu"}));
          set("title", HIW"明王"HIY"护法"NOR);
	set("gender", "女性" );
	set("age", 23);
	set("per", 21);
set("long", @LONG
这位孔雀公主是孔雀明王的女儿。孔雀明王被佛祖如来
押至灵山后，她由大鹏明王一手带大。说是侄女，与大
鹏明王实则有父女之情。
LONG );
	set("class", "yaomo");
	set("combat_exp", 2000000);
 	set("daoxing", 3000000);

	set("attitude", "peaceful");
	create_family("大雪山", 2, "弟子");
	set_skill("unarmed", 240);
	set_skill("cuixin-zhang", 240);
	set_skill("dodge", 240);
	set_skill("xiaoyaoyou", 240);
	set_skill("parry", 240);
       set_skill("throwing", 240);
	set_skill("sword", 240);
       set_skill("bainiao-jian", 240);
	set_skill("force", 240);   
	set_skill("ningxie-force", 240);
	set_skill("literate", 200);
	set_skill("spells", 240);
	set_skill("dengxian-dafa", 240);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 3000);
	set("max_force", 1500);
	set("mana", 3000);
	set("max_mana", 1500);	
	set("force_factor", 75);
	set("mana_factor", 76);
       set("eff_dx", -200000);
       set("nkgain", 400);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
            (: perform_action, "sword", "chaofeng" :),
             }) );

            setup();
	carry_object("/d/xueshan/obj/nihong-yuyi")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
       carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/sword/fenghuangqin")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="大雪山" ){
		if( (int)ob->query("family/generation") < 2  ){
			command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
		}
		else if( (int)ob->query("family/generation") ==2  ){
			command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣你家姑奶奶我了！\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command("blush ");
			command("say 你这个" + RANK_D->query_rude(ob) + "，这是你自愿的，可不算我挖墙角...\n");
			command("recruit " + ob->query("id") );
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 200000 ){
				command(":) ");
				command("say 好，" + RANK_D->query_respect(ob) + "既然到我门下就得给我争气，可不许偷懒！\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say 你还是找鹦鹉，乌鸦他们先练着吧。\n");
			}
		}
	}

	else{
		command("hmm");
		command("say 这位" + RANK_D->query_respect(ob) + "，你还是找鹦鹉，乌鸦他们先练练吧。\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

void init()
{       
	object me;

	me = this_player();

	::init();

	set("chat_chance", 5);
	set("inquiry", ([
		"name" : "不告诉你。\n",
		"here" : "你还没完了...别在这儿打搅！\n", 
		"大鹏王" : (: get_ice :),
		"大鹏明王" : (: get_ice :),
		"父王" : (: get_ice :),
	 ]) );

	set("chat_msg", ({
		"孔雀公主叹了口气。\n",	
		"孔雀公主自言自语道：也不知道父王的病什么时候能好。\n",
		"孔雀公主皱了皱眉道：按说这种草性暖，父王怎么会认为可以提炼寒毒呢？\n",
		"孔雀公主又叹了口气：做了这么久还不成，肯定还差点什么...这么多花草混来混去也没用呀？\n",
		"孔雀公主自言自语道：父王再弄不到寒毒，恐怕大事不妙了。\n",        
	}) );

	if ( ((string)me->query("gender") == "男性") && ((int)me->query("per") > 25) && ((int)me->query("combat_exp") < 10000) && (random(3) >1) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;

	switch( random(1) ) {
		case 0:
			command("say 好个美男子！\n");
			command("say 可惜是个绣花枕头...\n");
			command("kick " + me->query("id"));
			break;
	}
}

string get_ice(object me)
{
	object env;

	me = this_player();
	env = environment(this_object());

	if( (me->query_temp("ice_given") || (int)me->query("family/generation")<=2) && (string)env->query("short")=="小木屋" && (string)me->query("family/family_name")=="大雪山")
	{
		me->delete_temp("ice_given");
		message_vision("孔雀公主在$N耳边悄声说了几句话。\n", me);
		write("孔雀公主告诉你道：既然你想见他，这就让你去。\n");
		message_vision("只见孔雀公主伸手在桌子底下按了一按。\n", me);
		env->open_down();
		return "上来时敲一敲墙即可。\n";
	}
	else
	{
		return "大鹏明王就是我父王，我父王就是大鹏明王。\n";
	}
}

int accept_object(object me, object ob)
{
	if ( ((string)ob->query("id") != "lan bingkuai") && 
		((string)ob->query("id") != "shuangse bing") ) 
	{
		command("say 去！去！去！别来烦你家姑奶奶我！\n");
		//command("drop " + ob->query("id"));
		//this does not work due to time problem...
		//have to use call_out().
		//call_out("do_drop", 1, ob);
		return 1;
	}

	else {
		command("ah ");
		command("jump ");
		command("say 这位" + RANK_D->query_respect(me) + "真是有心人！\n");
		command("whisper " + me->query("id")+" 那我告诉你一个大秘密：我父王现在根本就不在冰宫里。他病得很厉害，正需要这种寒毒。\n");
		me->set_temp("ice_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

