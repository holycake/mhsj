inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string banghui,someone,something,skl;
	int i,money,exp,level;
	object ob;
	
	if(! arg)	return notify_fail("请使用help tisheng，查看此命令。\n");
	if(sscanf(arg,"%s %s",something,someone)!=2)
		return notify_fail("请使用help tisheng，查看此命令。\n");
	if(something=="-skl")	{
		if(sscanf(someone,"%s %s",skl,someone)!=2)
			return notify_fail("请使用help tisheng，查看此命令。\n");
	}
	if(something!="-skl"&&something!="-exp"&&something!="-zc")
		return notify_fail("请使用help tisheng，查看此命令。\n");
	if(! ob=present(someone,environment(me)))
		return notify_fail("这儿没有这么个人。\n");
	if(! ob->is_character())
		return notify_fail("看清楚，它不是生物。\n");
	if( userp(ob))
		return notify_fail("你只能提升本帮NPC帮众的技能。\n");
	if( !living(ob))
		return notify_fail("你得先把"+ob->query("name")+"弄醒再说。\n");
	if(me->is_fighting()||me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(ob->is_fighting()||ob->is_busy())
		return notify_fail(ob->query("name")+"正忙着呢。\n");
	if(! stringp(banghui=me->query("banghui")))
		return notify_fail("你没有参加任何帮会，无法提升任何NPC。\n");
	if( banghui!=(string)ob->query("banghui"))
		return notify_fail("你只能提升本帮会内的NPC帮众。\n");
	if(sizeof(children(base_name(ob)+".c"))>2)
		return notify_fail(ob->query("name")+"似乎现在不接受你的提升命令。\n");
	if(! ob->query("zhengzhao"))
		return notify_fail("你无法提升"+ob->name()+"！\n");
	if(something=="-skl")		{
		level=(int)ob->query_skill(skl,1);
		if(! level)
			return notify_fail(ob->query("name")+"并不会这门武功。\n");
		if(level>=200)
			return notify_fail(ob->query("name")+"的这门武功已学到顶了。\n");
		money=level*level*10;
		if((int)me->query("balance")<money)	{
		return notify_fail("你账上的钱不够，"+ob->query("name")+
		"的这门武功提升一级，需要"+MONEY_D->money_str(money)+"！\n");
		}
		ob->set_skill(skl,level+1);
		me->add("balance",-money);
		me->save();
		ob->save();
		write("你花了"+MONEY_D->money_str(money)+"，把"+
		ob->query("name")+"的"+to_chinese(skl)+"提升了一级！\n");
	}
	else if(something=="-exp")	{
		if((int)ob->query("combat_exp")>=2000000)
			return notify_fail(ob->query("name")+"的实战经验已经到顶了。\n");
		money=10000;
		if(me->query("balance")<10000)
			return notify_fail("你帐上的钱不够，"+ob->query("name")+
			"的战斗经验提升1000点需要一两黄金！\n");
		me->add("balance",-money);
		me->save();
		ob->add("combat_exp",1000);
		ob->save();
		write("你花了一两黄金，将"+ob->query("name")+
		"的战斗经验提升了一千点！\n");
	}
	else if(something=="-zc")	{
		money=10000;
		if(me->query("balance")<10000)
			return notify_fail("你帐上的钱不够，"+ob->query("name")+
			"的忠诚度提升一点需要一两黄金！\n");
		if((int)ob->query("zhongcheng")>=(int)ob->query("max_zhongcheng"))
			return notify_fail(ob->query("name")+"的忠诚度已经达到最大，不需要进行提升了。\n");
		me->add("balance",-money);
		me->save();
		if((int)ob->query("zhongcheng")+10>=(int)ob->query("max_zhongcheng"))
			ob->set("zhongcheng",(int)ob->query("max_zhongcheng"));
		else	ob->add("zhongcheng",10);
		ob->save();
		write("你花了一两黄金，将"+ob->query("name")+
		"的忠诚度提升了十点！\n");
	}
	return 1;
}


int help(object me)
{
        write(@HELP

指令格式：tisheng <-skl> <武功名称> <npc id>
          tisheng <-zc> <npc id>
          tisheng <-exp> <npc id>

这条指令可用来提升所属帮会中NPC的武功等级(skills)、
战斗经验(exp)和忠诚度(zhongcheng)。当你征招了某个
NPC后，为了提高它的战斗力及忠诚度，需要经常花钱对
其进行提升。
武功等级：将指定的武功提升一级(最大为200级)
          所需钱两与此NPC的当前武功等级有关。
战斗经验：每次提升，战斗经验长一千点(最大为2M)
          所需钱两为一两黄金。
忠诚度：  每次提升，忠诚度长十点，直至达到最大忠诚度。
          所需钱两为一两黄金。
HELP
        );
        return 1;
}
