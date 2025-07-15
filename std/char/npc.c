// npc.c

#include <command.h>
#include <ansi.h>

// inherit F_SAVE;
// inherit NPC;

#define MAX_OPPENENT 4

inherit CHARACTER;
inherit F_CLEAN_UP;

// inherit F_SAVE;
int do_jiaru(object target);

object carry_object(string file)
{
        object ob;

	if( file->query_unique() )  {
            if(clonep()) {  // only the cloned copy can have unique item.
		if( !objectp(ob = new(file->clone_file())) ) return 0;
            } else { // master copy can't have the unique item.
                     // mon 4/5/98
                if(!file->query("replace_file") ||
                   !objectp(ob = new(file->query("replace_file")))) return 0;
            }
	}
	else
		if( !objectp(ob = new(file)) ) return 0;

        ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
	object ob;

	ob = carry_object("/obj/money/" + type);
	if( !ob ) return 0;
	ob->set_amount(amount);
}

int accept_fight(object who)
{
	string att;

	att = query("attitude");

	if( is_fighting() )	switch(att) {
		case "heroism":
			command("say 哼！出招吧！\n");
			break;
		default:
			command("say 想倚多为胜，这不是欺人太甚吗！\n");
			return 0;
	}

	if( (int)query("gin") * 100 / (int)query("max_gin") >= 90
	&&	(int)query("kee") * 100 / (int)query("max_kee") >= 90
	&&	(int)query("sen") * 100 / (int)query("max_sen") >= 90 ) {
		switch(att) {
			case "friendly":
				command("say " + RANK_D->query_self(this_object())
					+ "怎么可能是" + RANK_D->query_respect(who)
					+ "的对手？\n");
				return 0;
			case "aggressive":
			case "killer":
				command("say 哼！出招吧！\n");
				break;
			default:
				if( !is_fighting() )
					command("say 既然" + RANK_D->query_respect(who)
						+ "赐教，" + RANK_D->query_self(this_object())
						+ "只好奉陪。\n");
		}
		return 1;
	} else
		return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
	object* enemy_list;
	int i, flag=0;

	// Are we at home already?
	if( !environment()
	||	environment()==home )
		return 1;

	// Are we able to leave?
	if( !living(this_object())
	||  this_object()->query_temp("no_return") ) return 0;

	//added by mon. 7/17/97
	// modified by tool
	if( is_fighting() )  {
	   enemy_list = query_enemy();
	   for(i=0; i<sizeof(enemy_list); ++i)  {
	       if(!enemy_list[i]) continue;
	      if( sizeof(enemy_list[i]->query_enemy()) > MAX_OPPENENT )  {
             message("vision", "\n"+this_object()->name() +
             "纵身向后一跃，拱手道：阁下武艺不凡，佩服，佩服！咱们后会有期！\n\n",
             environment(), this_object());
		     enemy_list[i]->remove_killer( this_object() );
			 remove_enemy( enemy_list[i] );
			 flag = 1;
			 break;
	      }
	   }
	   if( !flag )
	      return 0;
	}

	// Leave for home now.
	message("vision", this_object()->name() + "急急忙忙地离开了。\n",
		environment(), this_object());
	return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
	string *msg;
	int chance, rnd;

	if( !environment() ) return 0;

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
	mapping exits;
	string *dirs;
	int size; //added by mon 8/31/97

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	size=sizeof(dirs);
	if(size>0)
	  return command("go " + dirs[random(size)]);
        else
	  return 0;
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
	string spell_skill;

	if( stringp(spell_skill = query_skill_mapped("spells")))
		SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	string force_skill;

	if( stringp(force_skill = query_skill_mapped("force")))
		SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string skill, string action)
{
  object weapon=this_object()->query_temp("weapon");
  string weapon_skill,martial_skill;

  if (!weapon) weapon_skill="unarmed";
    else {
      if (weapon->query("use_apply_skill")) weapon_skill=weapon->query("apply/skill_type");
        else weapon_skill=weapon->query("skill_type");
}


	martial_skill = query_skill_mapped(skill);
//   tell_room(environment(),weapon_skill+"  "+skill+"\n");
//    if( stringp(martial_skill) )
//   weapon checking is added here. 

    if( stringp(martial_skill) && skill==weapon_skill)
		return SKILL_D(martial_skill)->perform_action(this_object(), action);		
}


/*
int do_jiaru(object target);
// this function is used to improve NPC's zhongcheng
// and to hire these NPC
int accept_object(object target,object obj)
{
	mapping data;
	string *who;
	string stuffid,stuffname;
        if(! query("zhengzhao"))        return 0;
        if(! target->query("banghui"))  {
                command("say 即然"+RANK_D->query_respect(target)
                +"如此客气，那我就收下了。\n");
                return 1;
        }
        if( target->query("banghui")==(string)this_object()->query("banghui")) {
		command("say 都是帮中兄弟，何必如此客气？\n");
		return 0;
        }
        if(query("zhengzhao")==1)       {
                command("say "+RANK_D->query_self(this_object())
                +"只对武功感兴趣，其他一概免谈。\n");
                return 0;
        }
        if(query("zhengzhao")==2)       {
		if(query_temp("oldsix/target")!=target)	{
                        command("say 无功不受禄，不知"+RANK_D->query_respect(target)+"给我"+obj->query("name")+"有何用意？\n");

                        return 0;

                }
                if(!obj->query("money_id"))     {
                        command("say "+RANK_D->query_self_rude(this_object())
                        +"只对钱有兴趣，你的破玩意自己留着吧。\n");
                        return 0;
                }
                if(obj->value()<query_temp("money")*10) {
                        command("say 我不是说过了吗？"+
                        chinese_number(query_temp("money")/1000)
                        +"两黄金，少一下子也不行！\n");
                        return 0;
                }
		if(query("banghui")&&query("zhongcheng")>target->query_per())	{
			command("say 若是收了你的钱，我如何对得起帮中其他弟兄？\n");
			return 0;
		}
		return do_jiaru(target);
        }
        if(query("zhengzhao")==3)       {
		data=query_temp("oldsix/target");
		if(! mapp(data))	data=([]);
		who=keys(data);
		if(member_array(target->query("id"),who)==-1)        {
                        command("say 你我素不相识，为何给"+
                        RANK_D->query_self(this_object())+obj->query("name")+
                        "？\n");
                        return 0;
                }
		sscanf(data[target->query("id")],"%s:%s",stuffid,stuffname);
		if(stuffname != obj->query("name") ||
			stuffid != obj->query("id"))	{
                        command("say "+RANK_D->query_respect(target)+
			"，我想要的是"+stuffname+"("+
			stuffid+")，不是"+obj->query("name")+
                        "("+obj->query("id")+")！\n");
                        return 0;
                }
		if(query("banghui")&&query("zhongcheng")>target->query_per())	{
			command("say 若是收了你的东西，我如何对得起帮中其他弟兄？\n");
			return 0;
		}
		return do_jiaru(target);
        }
}


// add by oldsix for npc to jiaru banghui;

int do_jiaru(object target)
{
	object lp_me,lp_target;
	object area;
	string bh_me,bh_target;
	mapping data;
	if(! (bh_target=target->query("banghui")))	{
		command("say 咦？你没有加入帮会，那我如何加入呢？\n");
		return 0;
	}
	if( bh_target==query("banghui"))	{
		command("say 咱们都是同帮弟兄，有事好商量嘛。\n");
		return 0;
	}
	if(sizeof(children(base_name(this_object())+".c"))>2)	{
		command("say "+RANK_D->query_self_rude(this_object())+
		"身体不适，有事下次再说吧。\n");
		return 0;
	}
	lp_target=new("/obj/lingpai");
	lp_target->create(bh_target);
	if(lp_target->query("no_use"))	{
		destruct(lp_target);
		command("say 你的帮会文件有问题，快与巫师联系吧。\n");
		return 0;
	}
	data=lp_target->query("npc");
	if(! mapp(data))	data=([]);
	data[query("id")]=query("name");
	lp_target->set("npc",data);
	lp_target->save();
	if(!undefinedp(target->query("oldsix_quest"))
	&& target->query("oldsix_quest/type")==4)	{
	target->set("oldsix_quest/over",1);
	tell_object(target,"你的任务已经完成，快回去交差吧。\n");
	}
	if(query("area_name")&&query("area_file"))	{
		data=lp_target->query("area");
		if(! mapp(data))	data=([]);
		data[query("area_name")]=query("area_file");
		lp_target->set("area",data);
		lp_target->save();
		area=new("/obj/area");
		area->create(query("area_name"));
		area->set("banghui",bh_target);
		if(! area->query("ziyuan")&& query("ziyuan"))	{
			area->set("ziyuan",query("ziyuan"));
			area->set("kaifa",query("kaifa"));
			area->set("jizhi",query("jizhi"));
		}
		area->save();
		destruct(area);
		if(!undefinedp(target->query("oldsix_quest"))
		&& target->query("oldsix_quest/type")==5)	{
		target->set("oldsix_quest/over",1);
		tell_object(target,"你的任务已经完成，快回去交差吧。\n");
		}
	}
	destruct(lp_target);
	if((bh_me=query("banghui")))	{
		lp_me=new("/obj/lingpai");
		lp_me->create(bh_me);
		if(! lp_me->query("no_use"))	{
		if(query("area_name")&&query("area_file"))	{
			data=lp_me->query("area");
			if(! mapp(data))	data=([]);
			map_delete(data,query("area_name"));
			lp_me->set("area",data);
			lp_me->save();
		}
                "/cmds/usr/tuoli.c"->yes_or_no("yes",this_object(),bh_me);
		}
	destruct(lp_me);
	}
	set("banghui",bh_target);
	add("zhongcheng",(query("max_zhongcheng")-query("zhongcheng"))*10/100);
	lp_me->save();
	if( query_temp("oldsix/target"))
		delete_temp("oldsix/target");
        command("say 既然"+RANK_D->query_respect(target)+
                "如此看得起"+RANK_D->query_self(this_object())+
                "，那我也不能对不起你啊。\n");
        message_vision("$N决定加入帮会「"+target->query("banghui")+"」！\n",
                this_object());
        message("channel:rumor",YEL"【谣言】某人："+query("name")+
        "加入帮会「"+bh_target+"」！\n"NOR,users());
        if(query("area_name")&&query("area_file"))
        message("channel:rumor",YEL"【谣言】某人："+query("area_name")+
        "被帮会「"+bh_target+"」吞并！\n"NOR,users());

	return 1;
}
*/
int do_jiaru(object target)
{
	object lp_me,lp_target;
	object area;
	string bh_me,bh_target;
	mapping data;
	if(! (bh_target=target->query("banghui")))	{
		command("say 咦？你没有加入帮会，那我如何加入呢？\n");
		return 0;
	}
	if( bh_target==query("banghui"))	{
		command("say 咱们都是同帮弟兄，有事好商量嘛。\n");
		return 0;
	}
	if(sizeof(children(base_name(this_object())+".c"))>2)	{
		command("say "+RANK_D->query_self_rude(this_object())+
		"身体不适，有事下次再说吧。\n");
		return 0;
	}
	lp_target=new("/obj/lingpai");
	lp_target->create(bh_target);
	if(lp_target->query("no_use"))	{
		destruct(lp_target);
		command("say 你的帮会文件有问题，快与巫师联系吧。\n");
		return 0;
	}
	data=lp_target->query("npc");
	if(! mapp(data))	data=([]);
	data[query("id")]=query("name");
	lp_target->set("npc",data);
	lp_target->save();
	if(!undefinedp(target->query("oldsix_quest"))
	&& target->query("oldsix_quest/type")==4)	{
	target->set("oldsix_quest/over",1);
	tell_object(target,"你的任务已经完成，快回去交差吧。\n");
	}
	if(query("area_name")&&query("area_file"))	{
		data=lp_target->query("area");
		if(! mapp(data))	data=([]);
		data[query("area_name")]=query("area_file");
		lp_target->set("area",data);
		lp_target->save();
		area=new("/obj/area");
		area->create(query("area_name"));
		area->set("banghui",bh_target);
		if(! area->query("ziyuan")&& query("ziyuan"))	{
			area->set("ziyuan",query("ziyuan"));
			area->set("kaifa",query("kaifa"));
			area->set("jizhi",query("jizhi"));
		}
		area->save();
		destruct(area);
		if(!undefinedp(target->query("oldsix_quest"))
		&& target->query("oldsix_quest/type")==5)	{
		target->set("oldsix_quest/over",1);
		tell_object(target,"你的任务已经完成，快回去交差吧。\n");
		}
	}
	destruct(lp_target);
	if((bh_me=query("banghui")))	{
		lp_me=new("/obj/lingpai");
		lp_me->create(bh_me);
		if(! lp_me->query("no_use"))	{
		if(query("area_name")&&query("area_file"))	{
			data=lp_me->query("area");
			if(! mapp(data))	data=([]);
			map_delete(data,query("area_name"));
			lp_me->set("area",data);
			lp_me->save();
		}
                "/cmds/usr/tuoli.c"->yes_or_no("yes",this_object(),bh_me);
		}
	destruct(lp_me);
	}
	set("banghui",bh_target);
	add("zhongcheng",(query("max_zhongcheng")-query("zhongcheng"))*10/100);
	this_player()->save();
	if( query_temp("oldsix/target"))
		delete_temp("oldsix/target");
        command("say 既然"+RANK_D->query_respect(target)+
                "如此看得起"+RANK_D->query_self(this_object())+
                "，那我也不能对不起你啊。\n");
        message_vision("$N决定加入帮会「"+target->query("banghui")+"」！\n",
                this_object());
        message("channel:rumor",YEL"【帮会势力】"+query("name")+YEL
        "加入帮会「"+bh_target+"」！\n"NOR,users());
        if(query("area_name")&&query("area_file"))
        message("channel:rumor",YEL"【帮会势力】"+query("area_name")+YEL
        "被帮会「"+bh_target+"」吞并！\n"NOR,users());

	return 1;
}


