//Cracked by Roath
// by snowcat 10/05/1997
// zhangmen.c 掌门
//modified for fangcun...

inherit NPC;
inherit F_SAVE;
#include <ansi.h>
string zm_apply();
string zname(object);
int rank_me();
#define DIRNAME "/d/qujing/xuanyuan/npc/"

#define MYFILE "/d/qujing/xuanyuan/npc/zhangmen.c"

void create()
{
	set_name("大弟子", ({ "zhang men", "zhangmen" }) );
	set("gender", "女性" );
	set("age", 30);
	set("str", 30);
	set("per", 30);
	set("int", 30);
   set("long", "掌门大师姐。" );
	set("attitude", "heroism");
	set("combat_exp", 3000000);
	set("daoxing", 3000000);
	set("current_player","none of us");

	setup();

}

void init()
{
	object me = this_object();

	me->create_identity("/d/qujing/xuanyuan/npc/daji", "/d/qujing/xuanyuan/mishi");
	
	add_action("do_bandage","bandage");

	if (me->query("current_player")=="none of us")
		me->reset_me(me);    
	me->restore();
	me->fully_recover(me);

	me->set("inquiry", ([
		"name" : "轩辕古墓掌门大师姐！\n",
		"here" : "这里即是那里，那里即是这里，又何必要问？\n",
		"掌门大弟子" : (: zm_apply :),		
		"掌门弟子" : (: zm_apply :),	
		"大弟子" : (: zm_apply :),	
		"掌门" : (: zm_apply :),
		"职位" : (: rank_me :),	 
	]) );

	//me->setup();
}

void reset_me (object me)
{
	int i;
	object *inv;
	mapping skill_status, map_status;
	string *skillnames, *mapnames;
    
	reset_eval_cost();
	if ( mapp(map_status = me->query_skill_map()) )
	{
		mapnames = keys(map_status);
		for(i=0; i<sizeof(mapnames); i++)
		{
			me->map_skill(mapnames[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) )
	{
		skillnames = keys(skill_status);
		for(i=0; i<sizeof(skillnames); i++)  
		{
			me->delete_skill(skillnames[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		destruct (inv[i]);
	}

	me->set_name("大师姐", ({ "zhang men", "zhangmen" }) );
	me->set("gender", "女性" );
	me->set("title",HIG+me->query("family/family_name")+NOR+zname(me));
	me->set("short",me->query("name")+"("+HIY+capitalize(me->query("id"))+NOR+")");
	me->set("attitude", "heroism");
	me->set("current_player","none of us");

	me->set("str", 30);
	me->set("per", 30);
	me->set("int", 30);
	me->set("age", 30);

	me->set("weapon", 0);
	me->set("armor", 0);

	me->set_skill("force",  60); 
	me->set_skill("spells", 60); 
	me->set_skill("unarmed",60);
	me->set_skill("sword",  60);
	me->set_skill("dodge",  60);
	me->set_skill("parry",  60);

	me->set("max_gin", 600);
	me->set("eff_gin", 600);
	me->set("gin", 600);
	me->set("max_kee", 600);
	me->set("eff_kee", 600);
	me->set("kee", 600);
	me->set("max_sen", 600);
	me->set("eff_sen", 600);
	me->set("sen", 600);
	me->set("force", 600);
	me->set("max_force", 600);
	me->set("mana", 600);
	me->set("max_mana", 600);
	me->set("force_factor", 600);
	me->set("mana_factor", 600);
	me->set("combat_exp", 1000000);
	me->set("daoxing", 1000000);

	//me->setup();
	reset_eval_cost();

}

int save_record(object me, object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status;
	string *skillnames, *mapnames;
	string *equipped_weapons, *equipped_armors;
	int i;

	reset_eval_cost();
	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]);
	me->set("per", hp_status["per"]);
	me->set("int", hp_status["int"]);
	me->set("age", hp_status["age"]);

	me->set("max_gin",     hp_status["max_gin"]);
	me->set("eff_gin",     hp_status["eff_gin"]);
	me->set("gin",         hp_status["gin"]);
	me->set("max_kee",     hp_status["max_kee"]);
	me->set("eff_kee",     hp_status["eff_kee"]);
	me->set("kee",         hp_status["kee"]);
	me->set("max_sen",     hp_status["max_sen"]);
	me->set("eff_sen",     hp_status["eff_sen"]);
	me->set("sen",         hp_status["sen"]);
	me->set("max_force",   hp_status["max_force"]);
	me->set("force",       hp_status["force"]);
	me->set("max_mana",    hp_status["max_mana"]);
	me->set("mana",        hp_status["mana"]);
	me->set("gender",      hp_status["gender"]);
	me->set("combat_exp",  hp_status["combat_exp"]);
	me->set("daoxing",  hp_status["daoxing"]);

	me->set("eff_gin", me->query("max_gin"));
	me->set("gin",     me->query("max_gin"));
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",   me->query("max_force")*2);
	me->set("mana",    me->query("max_mana")*2);

	skill_status = me->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames  = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++) 
		{
			me->delete_skill(skillnames[i]);
		}
	}

	skill_status = ob->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames  = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++) 
		{
			me->set_skill(skillnames[i], skill_status[skillnames[i]]);
		}
	}
  
	me->set("force_factor",me->query_skill("force",1)*3/4);

	reset_eval_cost();
	if (! me->query("new_player"))
	{
		me->save();
		reset_eval_cost();
		return 1;
	}

	me->set("new_player",0);

	if ( mapp(map_status = me->query_skill_map()) ) 
	{
		mapnames = keys(map_status);

		for(i=0; i<sizeof(mapnames); i++) 
		{
			me->map_skill(mapnames[i]);
		}
	}

	map_status = ob->query_skill_map();
	if ( mapp(map_status) ) 
	{
		mapnames  = keys(map_status);

		for(i=0; i<sizeof(mapnames); i++) 
		{
			me->map_skill(mapnames[i], map_status[mapnames[i]]);
		}
	}
  
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) 
	{
		destruct(inv[i]);
	}

	me->save();

	// --- 修改开始 ---
	equipped_weapons = ({});
	equipped_armors = ({});
	
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) 
	{
		if ( inv[i]->query("equipped") && !inv[i]->query_unique() )
		{
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				// 判断是武器 ("skill_type"存在)
				if(inv[i]->query("skill_type"))
				{
					if(obj->move(me))
						obj->wield();
					equipped_weapons += ({ base_name(inv[i]) });
				}
				// 否则为防具
				else 
				{
					if(obj->move(me))
						obj->wear();
					equipped_armors += ({ base_name(inv[i]) });
				}
			}
		}
	}

	// 清理旧的单一存档属性，并设置新的列表属性用于保存
	me->delete("weapon");
	me->delete("armor");
	me->set("equipped_weapons", equipped_weapons);
	me->set("equipped_armors", equipped_armors);
	// --- 修改结束 ---

	me->save();
	reset_eval_cost();

	return 1;
}

int convert_identity (object me, object ob)
{
	object who;

	reset_eval_cost();

	who = find_player(me->query("current_player"));
	if (! who)
	{
		// nobody to recover
	}
	else if (who->query("zhangmen/title_old"))
	{
		who->set("title",who->query("zhangmen/title_old"));
	}
	else if (who->query("family/family_name"))
	{
		who->set("title",
			sprintf("%s第%s代%s",
			who->query("family/family_name"),
			chinese_number(who->query("family/generation")),
			who->query("family/title")));
		who->save();
	}
	ob->set("zhangmen/base_name",base_name(me));
	ob->set("zhangmen/data_name",me->query_save_file());
	ob->set("zhangmen/title_old",ob->query("title"));
	ob->set("zhangmen/title",ob->query("family/family_name")+zname(ob));
	ob->set("title",ob->query("family/family_name")+zname(ob));
	ob->save();

	me->reset_me(me);
	me->set("name", ob->query("name") );
	me->set("gender", ob->query("gender") );
	me->set("current_player",ob->query("id"));
	me->set("title",HIG+ob->query("family/family_name")+NOR+zname(ob));
	me->set("short",me->query("name")+"("+HIY+capitalize(me->query("id"))+NOR+")");

	save_record(me, ob);

	return 1;
}

void self_adjust (object me)
{
	mapping skill_status;
	string *skillnames;
	int i;

	me->set("max_gin", 600);
	me->set("eff_gin", 600);
	me->set("gin", 600);
	me->set("max_kee", 600);
	me->set("eff_kee", 600);
	me->set("kee", 600);
	me->set("max_sen", 600);
	me->set("eff_sen", 600);
	me->set("sen", 600);
	me->set("force", 600);
	me->set("max_force", 600);
	me->set("mana", 600);
	me->set("max_mana", 600);
	me->set("force_factor", 60);
	me->set("mana_factor", 60);
	me->set("combat_exp", 100000);
	me->set("daoxing", 100000);

	skill_status = me->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++)
			me->set_skill(skillnames[i], 60);
	}

	carry_object("/d/obj/cloth/linen")->wear();
	me->save();

}

int init_identity (object me, object master, object where)
{
	reset_eval_cost();
	//me->setup();

	me->move(where);
	me->set("where",base_name(where));

	me->set("gender", master->query("gender") );
	me->set("current_master",master->query("id"));
	me->set("current_master_base_name",base_name(master));
	me->set("family/generation",master->query("family/generation"));
	me->set("family/family_name",master->query("family/family_name"));
	me->set("title",HIG+me->query("family/family_name")+NOR+zname(me));
	me->set("short",me->query("name")+"("+HIY+capitalize(me->query("id"))+NOR+")");

	me->restore();
	if (me->query("current_player")!="none of us")
		return 1;

	remove_call_out("self_adjust");
	call_out("self_adjust", 1, me);

	me->reset_me(me);
	me->set("new_player",1);
	save_record(me, master);

	return 1;
}

object find_and_restore(string name)
{
	object me = find_object(name);

	if (! me || ! me->restore())
		me = new (name);
	//me->setup();
	return me;
}

int fully_recover(object me)
{
	object *inv;
	object ob;
	string player_name;
	object current_player;
	string *item_list;
	int i;

	reset_eval_cost();

	me->set("eff_gin", me->query("max_gin"));
	me->set("gin",     me->query("max_gin"));
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",   me->query("max_force")*2);
	me->set("mana",    me->query("max_mana")*2);

	player_name = me->query("current_player");
	if (! player_name || player_name == "none of us")
		return 1;
  
	if (current_player = find_player(player_name))
	{
		if (current_player->query("combat_exp")>me->query("combat_exp"))
			save_record (me, current_player);
	}
	else if (current_player = LOGIN_D->find_body(player_name))
	{
		if (current_player->query("combat_exp")>me->query("combat_exp"))
			save_record (me, current_player);
	}
	else
	{
		seteuid(player_name);
		current_player = new(USER_OB);
		current_player->set("id", player_name);
		if (!current_player->restore())
		{
			destruct(current_player);
			return 1;
		}
		export_uid(current_player);
		seteuid(getuid());
		current_player->setup();
		if (current_player->query("combat_exp")>me->query("combat_exp"))
			save_record (me, current_player);
		destruct (current_player);
	}

	inv = all_inventory(me);
	while (inv && sizeof(inv))
	{
		destruct (inv[0]);
		inv = all_inventory(me);
	}

	// --- 修改开始 ---
	// 加载并佩戴所有保存的武器
	if (item_list = me->query("equipped_weapons"))
	{
		for(i=0; i<sizeof(item_list); i++)
		{
			ob = new(item_list[i]);
			if(ob && ob->move(me))
				ob->wield();
		}
	}

	// 加载并穿上所有保存的防具
	if (item_list = me->query("equipped_armors"))
	{
		for(i=0; i<sizeof(item_list); i++)
		{
			ob = new(item_list[i]);
			if(ob && ob->move(me))
				ob->wear();
		}
	}
	// --- 修改结束 ---
	
	reset_eval_cost();
	return 1;
}

string zm_apply()
{
	object me = this_object();
	object ob = this_player();

	if (me->query("family/family_name") != ob->query("family/family_name")) 
	{
		return "我便是本派掌门师姐！\n";
	}
	if (ob->query("betrayer") || ob->query("betray/count"))
	{
		return "你曾叛师欺祖，言无信行不轨，岂能出任掌门弟子一职！\n";
	}
	if (me->query("current_player") == ob->query("id")) 
	{
		return "你又糊涂了！\n";
	}
	ob->set_temp("xuanyuan_zm_applied", 1);
	return "我轩辕古墓掌门大师姐一定要强。\n如有意出掌此位，还请一战。\n";
}

int accept_fight(object ob)
{
	int i;
	object* inv;

	object me = this_object();


	if (me->query("current_player") == ob->query("id")) 
	{
		return notify_fail("你又糊涂了！\n");
	}

	if (me->is_fighting())
	{
		command ("say 失陪了！\n");
		return notify_fail("这位大师姐尚在比武之中，请稍候。\n");
	}

	if (ob->query_temp("xuanyuan_zm_applied"))
	{
		command("say 好！尚请未来的"+zname(ob)+"手下留情。\n");
	}
	else
	{
		command("say 拳脚无眼，若是伤到人就不好了。\n");
		return 0;
	}

	me->set_temp("zhangmen/kill",0);
	remove_call_out("check_result");
	call_out("check_result", 1, me, ob);
  
	fully_recover (me);
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) 
	{
		if( inv[i]->query_unique()||inv[i]->query("no_zm") ) {
			message_vision("突然间，$n化一道白光飞去，无影无踪！\n",me,inv[i]);
			destruct(inv[i]);
		}
	}

	return 1;
}

int check_result(object me, object ob)
{
	int my_max_kee, his_max_kee;

	my_max_kee  = me->query("max_kee");
	his_max_kee = ob->query("max_kee");

	if (me->is_fighting())
	{
		call_out("check_result",1, me, ob);
		return 1;
	}

	if ( !living(me) 
		|| (int)me->query("kee") < 1 
		|| (int)me->query("sen") < 1 ) return 1;

	if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
	{
		object who;

		if ( !living(me) 
			|| (int)me->query("kee") < 1 
			|| (int)me->query("sen") < 1 ) return 1;

		message_vision ("$N翻身下拜，连声佩服！\n",me);

		if (me->query_temp("zhangmen/kill") && ob->query_temp("xuanyuan_zm_applied"))
		{
			message_vision ("$N皱了皱眉道：此次比武我未能静心尽力，希望重新来过。\n", me);
			return 1;
		}

		if( ob->query_temp("xuanyuan_zm_applied") != 1 )
			return 1;	
	
		if (me->query("current_master"))
		who = present(me->query("current_master"),environment(me));
		if (who && who->query("id")!=me->query("current_master"))
			who = 0;

		if (who)
		{ 
			call_out("master_announce",1,me,who,ob);
		}
		else
		{
			message_vision("$N躬身对$n说道：恭请"+RANK_D->query_respect(ob)+"随我一同向师祖禀明出让掌门大师姐一事。\n", me, ob);
			command ("follow "+ob->query("id"));
			if (! me->query("where"))
				me->set("where",base_name(environment(me)));
			remove_call_out("find_master");
			call_out("find_master", 1, me, ob);
		}
		return 1;
	}

	if (( (int)ob->query("kee")*100/his_max_kee)<=50)
	{
		message_vision ("$N将$n扶起。\n",me,ob);
	}

	return 1;  
}

void find_master(object me, object ob)
{
	object who = present(me->query("current_master"),environment(me));

	if (who && who->query("id")!=me->query("current_master"))
		who = 0;

	if (! who)
	{
		remove_call_out("find_master");
		call_out("find_master", 1, me, ob);
	}
	else
	{
		message_vision ("$N见了师父赶紧下拜，又抬起头朝$n使了个眼色。\n\n",me,ob);
		message_vision ("$N微微地点了点头。\n\n",who);
		message_vision ("$N退下。\n\n",me);
		me->set_leader(0);
		call_out("master_announce",1,me,who,ob);
		me->move(me->query("where"));
	}
}

void master_announce(object me, object who, object ob)
{
	CHANNEL_D->do_channel(who,"chat","本派掌门大师姐"+ob->query("name")+"今日走马上任。恭请各位仙长多加捧场！");
	ob->delete_temp("xuanyuan_zm_applied");
	me->set("new_player",1);
	convert_identity (me, ob);
}

string query_save_file()
{
	string str = query("save_file");
	int i;

	if (str)
		return str;

	str = DATA_DIR+"zhangmen/zhangmen_"+query("current_master");
	for (i = 0; i < sizeof(str); i++)
		if (str[i]==' ') str[i] = '_';

	return str;
}

void set_save_file(string str)
{
	set("save_file",str);
}

int do_bandage(string arg)
{
	object who = this_player();
	object me = present("zhang men",environment(who));

	if (! arg || me != present(arg, environment(me)))
		return 0;

	message_vision ("$N别有用心地要给$n包扎伤口。\n",who,me);
	call_out("no_bandage",2,who,me);
	return 1;
}

void no_bandage(object who, object me)
{
	message_vision ("$N向$n摇了摇头。\n",me,who);
}

void kill_ob(object ob)
{
	object me = this_object();
	object master;

	if (me->query("current_master"))
		master = present(me->query("current_master"),environment(me));
	if (master)
		master->kill_ob(ob);
	else
	{

	}
		
	me->set_temp("zhangmen/kill",1);
	::kill_ob(ob);
}

void create_identity (mixed master, mixed where)
{
	object master_ob, where_ob;

	if (this_object()->query("created"))
		return;
	this_object()->set("created",1);

	if (objectp(master))
		master_ob = master;
	else
	{
		master_ob = new (master);
		master_ob->restore();
	}

	if (objectp(where))
		where_ob = where;
	else
	{
		call_other(where,"???");
		where_ob = find_object(where);
	}
	init_identity (this_object(), master_ob, where_ob);
}

string zname(object ob)
{
	return HIG"九幽玄狐圣姬"NOR;
}

void unconcious()
{
  die();
}

int rank_me()
{
	object me = this_player();
	object ob = this_object();
	int exp;

	exp = (int)me->query("combat_exp");

	if (me->query("title") == HIG"轩辕古墓九幽玄狐圣姬"NOR)
		return notify_fail("你已经是「九幽玄狐圣姬」，立于幽冥之巅。\n");

	if (me->query("family/family_name") == "轩辕古墓")
	{
		if (exp <= 20000) {
			me->set("title", "轩辕古墓洗骨侍姬");
		} else if (exp <= 50000) {
			me->set("title", "轩辕古墓狐媚侍童");
		} else if (exp <= 100000) {
			me->set("title", "轩辕古墓绮罗门徒");
		} else if (exp <= 200000) {
			me->set("title", "轩辕古墓魅影使女");
		} else if (exp <= 500000) {
			me->set("title", "轩辕古墓玉骨幽娘");
		} else if (exp <= 1000000) {
			me->set("title", "轩辕古墓迷心妖女");
		} else if (exp <= 2000000) {
			me->set("title", "轩辕古墓落魄妲魂");
		} else {
			me->set("title", "轩辕古墓天狐女御");
		}

		tell_room(environment(me), 
			HIR"" + ob->query("name") + "轻启朱唇，缓缓说道：" +
			me->query("name") + "容貌妖异，气质出尘，媚而不俗，柔而不弱，"
			"深得我轩辕古墓之传承。\n今授其「" + me->query("title") + "」之号，"
			"愿你不坠妲后遗风，行在幽冥之界，惑在凡尘之间。\n"NOR,
			({me, me}));
	}
	return 1;
}
