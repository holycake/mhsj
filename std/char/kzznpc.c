#include <ansi.h>
inherit F_SAVE;
inherit NPC;

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
	save();
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

