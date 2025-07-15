#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *dir,*area,area_name;
	string msg;
	object dipan;
	string banghui;
          string *npc_bh=({"明教","日月教","天地会","长安城"});
	int kaifa,money,i;
	if(! stringp(banghui=me->query("banghui")))
		return notify_fail("你没有加入任何帮会，无法开发帮会所属地盘。\n");
	if(member_array(banghui,npc_bh)!=-1)
		return notify_fail("NPC帮会的玩家无权开发地盘。\n");
	dir=get_dir("/data/area/",0);
	if(! dir)	dir=({});
	area=({});
	dipan=new("/obj/area");
	for(i=0;i<sizeof(dir);i++)	{
		sscanf(dir[i],"%s.o",area_name);
		dipan->create(area_name);
		if(! dipan->query("ziyuan"))	continue;
		if(dipan->query("banghui")!=banghui)	continue;
		area+=({area_name});
	}
	if(! arg|| member_array(arg,area)==-1)	{
		msg=HIC"你可以开发的地盘\n\n"NOR;
		msg+=sprintf("%-16s%-10s%-10s%-10s\n",
		"地盘名称","资源","开发度","基值");
		msg+="―――――――――――――――――――――――――――――――――――――\n";
		for(i=0;i<sizeof(area);i++)	{
			dipan->create(area[i]);
			msg+=sprintf("%-16s%-10s%-10d%-10s\n",
			area[i],dipan->query("ziyuan"),dipan->query("kaifa"),
		MONEY_D->money_str(dipan->query("jizhi")*10));
		}
		destruct(dipan);
		me->start_more(msg);
		return 1;
	}
	dipan->create(arg);
	kaifa=dipan->query("kaifa");
	money=kaifa*10000;
	if((int)me->query("balance")<money)	{
		destruct(dipan);
		return notify_fail("你帐上的钱不够，开发"+arg+"至少要"+
		MONEY_D->money_str(money)+"！\n");
	}
	money=-money;
	me->add("balance",money);
	me->save();
	if(kaifa<100)	dipan->set("kaifa",kaifa+1);
	else	{
		destruct(dipan);
		return notify_fail(arg+"的开发度已达到最大，不需再开发。\n");
	}
	dipan->save();
	destruct(dipan);
	write("你花费了"+MONEY_D->money_str(-money)+"开发"+arg+
	"，");
	write("开发度上升了一点！\n");
	return 1;
}
	
int help(object me)
{
        write(@HELP

指令格式：kaifa [地盘名称]

用于开发帮会中地盘，增加帮会收入。

HELP
        );
        return 1;
}

