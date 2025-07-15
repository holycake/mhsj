#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
	object lp;
	string banghui,msg;
	string str;
	object target,*name;
	int i,cnt;

	if(! (banghui=me->query("banghui")))
			return notify_fail("只有帮会的帮主才能使用这条命令。\n");
	lp=new("/obj/lingpai");
	lp->create(banghui);
	if((string)lp->query("bangzhu_id")!=me->query("id"))	{
		destruct(lp);
		return notify_fail("只有帮主才能使用这条指令。\n");
	}
	destruct(lp);
	if(! arg)	{
		msg=HIR"               黑名单\n"NOR;
		msg+="―――――――――――――――――――――――――――――――――――――\n";
		name=users();
		cnt=0;
		for(i=0;i<sizeof(name);i++)	{
			if(name[i]->query("vendetta/"+banghui))	{
			msg+=sprintf("%-18s%s",name[i]->query("name")+"("+name[i]->query("id")+")",
			(cnt%4==3? "\n":""));
			cnt++;
			}
		}
		if(cnt==0||(cnt%4))	msg+="\n";
		msg+="―――――――――――――――――――――――――――――――――――――\n";
		me->start_more(msg);
		return 1;
	}
	if(sscanf(arg,"-a %s",str)==1)	{
		target=find_player(str);
		if(! target&&!wizardp(me))
			return notify_fail("你想追杀的玩家不在游戏中。\n");
		if(!wizardp(me))
			return notify_fail("你想追杀的玩家不在游戏中。\n");
		if(target==me)
			return notify_fail("追杀自己？没问题吧。\n");
		if(target->query("vendetta/"+banghui))
			return notify_fail("此玩家已在黑名单中。\n");
		target->set("vendetta/"+banghui,1);
		target->save();
		if(banghui==(string)target->query("banghui"))
		message("channel:rumor",
		YEL"〖江湖传闻〗"YEL+ "「"+banghui+"」开始追杀本帮"WHT+
		target->query("name")+"("+target->query("id")+")"YEL"。\n"NOR,users());
		else
		message("channel:rumor",YEL"〖江湖传闻〗"YEL+ "「"+banghui+"」开始追杀"WHT+target->query("name")+"("+target->query("id")+")"YEL"。\n"NOR,users());
		return 1;
	}
	if(sscanf(arg,"-d %s",str)==1)	{
		target=find_player(str);
		if(! target&&!wizardp(me))	return notify_fail("此处没有这么个玩家。\n");
		if(! target->query("vendetta/"+banghui))
			return notify_fail("此玩家并不在追杀的黑名单中。\n");
		target->delete("vendetta/"+banghui);
//		target->remove_all_killer();
		target->save();
		message("channel:rumor",
		YEL"〖江湖传闻〗「"+banghui+"」停止追杀"WHT+target->query("name")+"("+target->query("id")+")"YEL"。\n"NOR,users());
		return 1;
	}
	return notify_fail("指令格式：zhuisha [-a][-d]<玩家ID>\n");
}

int help(object me)
{
        write(@HELP
指令格式：zhuisha [-a][-d]<对象ID>
本指令为帮主专用，不加参数显示目前在线被
追杀的玩家。-a 追杀某玩家，-d 取消追杀某
玩家。当被追杀玩家死亡，则自动停止追杀。
HELP
        );
        return 1;
}
