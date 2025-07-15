//liuer-mihou.c weiqi...98/05/13

#include <ansi.h>
#define MAX_TRY 20
inherit NPC;
string ask_me();

void create()
{
	set_name(YEL"六耳猕猴"NOR, ({"liuer mihou", "liuer", "mihou"}));
	set("title", RED"灵通子"NOR);
	set("gender", "男性" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	set("long", "六耳猕猴早年拜在镇元大仙门下，学得一身好本领。\n后来他自觉跟镇元大仙差不多了，便开始不安分起来，\n居然去果园偷吃人参果，结果是果子没吃着反而被镇元大仙逮住，\n痛加斥责后逐出了门墙。\n");
	set("class", "xian");
	set("daoxing", 5000000);
	set("combat_exp", 5500000);
	set("attitude", "peaceful");
	//create_family("五庄观", 2, "弟子");
	set("rank_info/respect", "猴爷");
	set_skill("unarmed", 380);
	set_skill("wuxing-quan", 380);
	set_skill("dodge", 350);
	set_skill("baguazhen", 350);
	set_skill("parry", 380);
	set_skill("hammer", 360);
	set_skill("kaishan-chui", 380);
	set_skill("force", 360);   
	set_skill("zhenyuan-force", 360);
	set_skill("literate", 350);
	set_skill("spells", 380);
	set_skill("taiyi", 380);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("dodge", "baguazhen");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 3000);
	set("max_sen", 3000);
	set("force", 10000);
	set("max_force", 5000);
	set("mana", 10000);
	set("max_mana", 5000);	
	set("force_factor", 150);
	set("mana_factor", 180);

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	set("chat_chance_combat", 30);
	set("chat_msg_combat", 
	({
		(: cast_spell, "zhenhuo" :),
	}) );

	set("inquiry", ([
		"name": "齐天大圣孙悟空是也。\n",
		"here": "。。。\n",
		"人参果": "猴爷我最喜欢的就是人参果。\n",
		"杀人": "杀人？只要你有人参果，什么都好商量。\n",
		"秘诀": "秘诀？只要你有人参果，什么都好商量。\n",
		"猕猴手记": "手记？只要你有人参果，什么都好商量。\n",
                "包裹"     : (: ask_me :),
                 "真假"     : (: ask_me :),
                 "美猴王"     : (: ask_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}

int accept_object(object me, object ob)
{
	object book;

	if ( (string)ob->query("id") != "renshen guo" ) {
		message_vision("六耳猕猴尖声叫道：去！去！去！你家猴爷没空理你！\n", me);
		command("kick " + me->query("id"));
		//call_out("do_drop", 2, ob);
		return 1;
	}

	else {
		command("jump ");
		command("say 这位" + RANK_D->query_respect(me) + "果然是痛快人！\n");
		//first give a book...
		book = new("/d/obj/book/mihou-book");
		book->move(me);
		message_vision("$N对$n道：那猴爷我也不能小气。说罢递给$n一本小册子。\n除了这本书外，别的我帮不上，但杀个人是没问题的。你要杀人的话，尽可附耳说来(whisper liuer enemy_id)。\n", this_object(), me);
		me->set_temp("rsg_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

void relay_whisper(object me, string msg)
{
	object target, where;

	if (me->query_temp("rsg_given") != 1)
	{
		message_vision((string)this_object()->query("name") + "对着$N冷冷地看了一眼。\n", me);
		return;
	}

	if( query_temp("I_am_busy") == 1 )
	{
		message_vision((string)this_object()->query("name") + "对$N道：我现在正忙着，你等会再来吧。\n", me);
		return;
	}

	
	target = find_player(msg);
	if( !target )
	{ 
		message_vision((string)this_object()->query("name") + "对$N说道：好像找不到这个人。\n", me);
		return;
	}

	where = environment(target);
	if( !where )
	{ 
		message_vision((string)this_object()->query("name") + "对$N说道：这个人是有，但是躲起来了。\n", me);
		return;
	}

	//now got the target player...
	message_vision((string)this_object()->query("name") + "对$N说道：好，你就静候佳音吧！\n", me);

	me->delete_temp("rsg_given");
	set_temp("I_am_busy", 1);
	set_temp("kill_count", MAX_TRY);

	remove_call_out ("try_kill");
	call_out ("try_kill", 3, msg);
	call_out ("check_finish", 3, msg);
	//note, here we still use target id for future trying...
}

void check_finish(string target_id)
{
	object target;

	//here alway set fali back, since liuer mihou is in a "bian" status...
	if( (int)this_object()->query("mana") < (int)this_object()->query("max_mana") )
		this_object()->set("mana", 2*(int)this_object()->query("max_mana"));

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}

	if( target->is_ghost() )
	{//means the target is dead.
		//bian back now...
		command("bian");
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		remove_call_out ("try_kill");
		remove_call_out ("check_finish");
		return;
	}
	else
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}
}

void  try_kill(string target_id)
{
	object target, where;

	if( (int)query_temp("kill_count") <= 0 )
	{//tried too long
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		return;
	}

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	where = environment(target);
	if( !where )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	//now kill...
	if( where != environment(this_object()) )
	{
		this_object()->move(where);
		message_vision(YEL "只见几道金光乱晃不止，$N一个筋斗翻了出来。\n" NOR, this_object());
	}
	message_vision(RED "$N抓耳挠腮地对$n尖声说道：到了阎王那儿休怪猴爷无情。阁下要是有人参果我一样能替你杀人。\n" NOR, this_object(), target);

	if( (int)query_temp("kill_count") == MAX_TRY ) 
	{//first time, always need to initialize kill...
		command("bian " + target_id);
		//this_object()->kill_ob(target);
		//need consider this carefully, is it ok to make safe place unsafe?
		command("kill " + target_id);
	}
	else command("kill " + target_id);
	//problem here, if kill_ob(), may bypass no_fight, ...etc;
	//if kill command, may confuse with NPC of the same name?
	command("follow "+target_id);

	set_temp("kill_count", (int)query_temp("kill_count")-1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 900, target_id);//try every 15 minutes.
}

//LPG 19990925 真假美猴王

string ask_me()
{
	this_player()->set_temp("liuer-mihou_ask","done");
	call_out("autokill",1,this_player(),this_object());
	return "嘿嘿";
}
void autokill (object me, object who)
{
  message_vision ("$n大喝一声要杀死$N！\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N大怒：哪个泼贼子冒充你家猴爷！\n",this_player());

  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
}

void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object xiangjiao;
  message_vision(HIY "\n观音突然从彩云间现身。\n" NOR,me);
  message_vision(HIY "\n观音对$N一点手，你这猴头！\n" NOR,me);
  message_vision(HIY "$N哎呀一声，现了真身。\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
  	ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
	message_vision(HIC "观音说道：这厮我带走，你安心取经去吧。\n\n" NOR,me);
  	xiangjiao = new ("/d/obj/drug/xiangjiao");
       xiangjiao -> move(ob);
	message_vision("$N给你一些东西。\n\n",me);
  	call_out ("pusa_appearing",1,ob);
  }
  ob->set_temp("liuer-mihou_ask","no");
  message_vision("$N悻悻地走了。\n\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/dntg/hgs/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}
