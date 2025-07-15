#include <ansi.h>
inherit F_CLEAN_UP;

string *npc_bh=({"明教","日月教","天地会","丐帮"});

int main(object me, string arg)
{
	object area;
	string msg,file;
	mixed *dir;
	int i;

	msg=sprintf(HIC"%-16s%10s%10s%8s%10s%10s%8s\n"NOR,
		"地盘","所属帮会","资源","开发度","基值","上日收入","(白银)");
	msg+="―――――――――――――――――――――――――――――――――――――\n";
	dir=get_dir("/data/area/",0);
	if(! dir)	dir=({});
	area=new("/obj/area");
	for(i=0;i<sizeof(dir);i++)	{
		if(sscanf(dir[i],"%s.o",file)==1)	{
		area->create(file);
		if(member_array((string)area->query("banghui"),npc_bh)!=-1)	{
		msg+=sprintf("%-16s%10s%10s%6s%12s%10s\n",
		file,area->query("banghui"),
		"-","-","-","-");
		}else	{
		msg+=sprintf("%-16s%10s%10s%6s%12s%10s\n",
		file,area->query("banghui"),
		area->query("ziyuan")?area->query("ziyuan"):"-",
		area->query("ziyuan")?(int)area->query("kaifa")+"%":"-",
		area->query("ziyuan")?(int)area->query("jizhi")/10+"两":"-",
		(int)area->query("last_money")/100+"两");
		}
		}
	}
	msg+="―――――――――――――――――――――――――――――――――――――\n";
	destruct(area);
	msg+="\n";
	me->start_more(msg);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式：dipan
用于显示所有地盘的所属帮会。
HELP
        );
        return 1;
}
