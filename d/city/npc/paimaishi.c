// 拍卖师

inherit NPC;
#include <ansi.h>;
int begin_paimai(string name,int value ,int paimai_count,int m);
int go_paimai(string id,string name,int value,int num,int m);
int report_paimai(object buyer,int money,int num);
int finish_paimai(int num,int sign);
int pay_back(string id, int amount);
int delete_ob(int num);
void create()
{
        set_name("拍卖师", ({ "paimai shi", "ji", "shi" }) );
		set("nickname", HIW "天下第一锤" NOR);
        set("gender", "男性");
        set("age", 45);
        set("no_get", 1);
        set("long",
                "这是一位瘦高的中年人，因为公正无私而被推为天下第一拍卖师。\n");
        set("combat_exp",600000);
        set("shen", 0);
	set("attitude", "friendly");

        set("apply/attack", 100);
        set("apply/defense", 100);

        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("max_force", 8000);
        set("eff_force",8000);
        set("force",8000);
	
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("sword",300);
        set_skill("parry",300);
        set_skill("dodge", 300);

	    setup();

        carry_object(__DIR__"obj/cloth")->wear();
}


void init()
{
        ::init();
        add_action("do_paimai", "paimai");
		add_action("do_paimailist", "paimailist");
		add_action("do_yao", "yao");
        
}
int do_paimai(string arg)
{
	object who,ob;
	int money,clone_number,paimai_count,i,value,sale_price;
	string id,file_name;
	mapping fpaimai,vpaimai,ipaimai,npaimai,lpaimai,opaimai,spaimai;
	string* terms;
	
	fpaimai = query("fpaimai");
	vpaimai = query("vpaimai");
	ipaimai = query("ipaimai");
	npaimai = query("npaimai");
	lpaimai = query("lpaimai");
	opaimai = query("opaimai");
	spaimai = query("opaimai");
	
	who=this_player();
	
	if( who->is_busy() )
         return notify_fail("你的动作还没有完成，不能提交物品进行拍卖。\n");
    if( !arg || sscanf(arg, "%s with %d",id, money)!=2 )
		return notify_fail("指令格式：paimai <物品id> with <底价(silver为单位)> \n");
	if( !ob=present(id, who))
		return notify_fail("你身上没有这样东西。\n");
	if( ob->query("money_id") )	
		return notify_fail("你要拍卖「钱」？\n");
	
	if (ob->query("value")==0 || money==0)
		return notify_fail("不值钱，你就别卖了！\n");
	if (ob->query("no_paimai"))
		return notify_fail("这样东西不能拍卖了！\n");
	if (money>ob->query("value")*4/500)
		return notify_fail("要价太高了，你可能卖不出去！\n");
	if (who->query("balance")<10000)
		return notify_fail("你账号里的钱不够支付手续费！\n");
	who->add("balance",-10000);
	
	command("chat "+"有人提交"+NOR+ob->query("name")+HIW+"进行拍卖。"NOR);
	sscanf(file_name(ob),"%s#%d",file_name,clone_number);

	if( mapp(fpaimai) &&  sizeof(fpaimai) )
		add("total_number",1);
	else
		set("total_number",0);
	
	value = ob->query("value");
	sale_price= ob->query_temp("sale_price");
	if (sale_price>0)
		sale_price= sale_price>value?value:sale_price;

	set("fpaimai/"+ sprintf("%d",query("total_number")),file_name);
	set("vpaimai/"+sprintf("%d",query("total_number")), money);
	set("ipaimai/"+sprintf("%d",query("total_number")), who->query("id"));
	set("npaimai/"+sprintf("%d",query("total_number")), ob->query("name"));
	set("lpaimai/"+sprintf("%d",query("total_number")), 1);
	set("opaimai/"+sprintf("%d",query("total_number")), who->query("id"));
	set("spaimai/"+sprintf("%d",query("total_number")), sale_price);
	
	if (query("total_number")==0 || query("lpaimai/"+sprintf("%d",query("number")))==0)
	{
		set("value",money);
		set("pnum",0);
		set("number",query("total_number")>0?query("number")+1:0);
		call_out("begin_paimai",5,ob->query("name"),money,query("number"),0);
	}
	destruct(ob);
	return 1;
}
int begin_paimai(string name,int money,int num,int m)
{
	m+=1;
	if (m==1)
	{
		command("chat "+"现在开始拍卖 "NOR+name+HIW+" 的所有权。"+NOR);
	}
	set("on_paimai",1);
	command("chat  "+NOR+name+HIW+" 底价 "+chinese_number(money)+"两银子 第"+chinese_number(m)+"次");
	if (!(m==3))
		call_out("begin_paimai",20,name,money,num,m);
	else
		call_out("finish_paimai",2,num,0);	
}
int finish_paimai(int num,int sign)
{
	string id,owner_id;
	object buyer,owner;
	int i;

	
	id=query("ipaimai/" + sprintf("%d", num));
	owner_id=query("opaimai/" + sprintf("%d", num));
	set("lpaimai/"+sprintf("%d",num), 0);
		
	buyer=find_player(id);
	owner=find_player(owner_id);
	if (sign==0)
	{
		if(owner)
			tell_object(owner,HIR"你的东西没有卖出去，请在十分钟内来拍卖场取回自己的物品。\n"NOR);
	}
	else		
	{
		command("chat  成交!"+buyer->query("id")+"获得了 "+NOR+query("npaimai/" + sprintf("%d", num))+HIW+" 的所有权。"+NOR);
		if (buyer)
			tell_object(buyer,HIR"你获得了 "+NOR+query("npaimai/" + sprintf("%d", num))+HIR+" 的所有权，请在十分钟内来拍卖场取回你买的东西。\n"NOR);
		if (owner)
			tell_object(owner,HIR"你的"+NOR+query("npaimai/" + sprintf("%d", num))+HIR+"卖了"
			+chinese_number(query("vpaimai/" + sprintf("%d", num)))+"两银子，扣除5%手续费，其余的已经加入你的户头了。\n"NOR);	
	}
	set("on_paimai",0);
	
	pay_back(owner_id,query("vpaimai/" + sprintf("%d", num))*95);
	
	call_out("delete_ob",36000,num);

	num=num+1;
	if (query("lpaimai/" + sprintf("%d", num))==1)
	{
		set("value",query("vpaimai/" + sprintf("%d", num)));
		set("number",num);
		set("pnum",0);
		call_out("begin_paimai",5,query("npaimai/" + sprintf("%d", num)),query("vpaimai/" + sprintf("%d", num)),num,0);
	}
	return 1;
}
int report_paimai(object buyer,int money,int num)
{
	remove_call_out("begin_paimai");
	remove_call_out("finish_paimai");
	remove_call_out("go_paimai");
	
	if (query("pnum"))
	{
		pay_back(query("ipaimai/" + sprintf("%d", num)),query("vpaimai/" + sprintf("%d", num))*100);
	}
	add("pnum",1);
	buyer->add("balance",(0-money*100));
	set("vpaimai/"+sprintf("%d",num), money);
	set("ipaimai/"+sprintf("%d",num), buyer->query("id"));
	set("value",money);
	command("chat  "+buyer->query("id")+" 出价 "+chinese_number(money)+"两银子 购入"+NOR+query("npaimai/" + sprintf("%d", num))+HIW"的所有权。");
	call_out("go_paimai",5,buyer->query("id"),query("npaimai/" + sprintf("%d", num)),money,num,0);
	return 1;
}
int pay_back(string id, int amount)
{
    object who;
    
    who=find_player(id);
    if(who)
	{
		who->add("balance",amount);
		if(!who->save()) 
		{
			log_file("paimai_log","Failed to return "+amount+
				" coin to "+id+"\n");
			return 0;
		}
	log_file("paimai_log","pay "+amount+" to "+id+"\n");
	return 1;
    } 
	else
	{
		who=new(USER_OB);
		who->set("id",id);
		if(!who->restore())
		{
			log_file("paimai_log","Failed to return "+amount+
				" coin to "+id+"\n");
			destruct(who);
			return 0;
		}
		else 
		{
			who->add("balance",amount);
			if(!who->save())
			{ // save() will not erase autoload.
				log_file("paimai_log","Failed to return "+amount+
					" coin to "+id+"\n");
				destruct(who);
				return 0;
			} 
			log_file("paimai_log","pay "+amount+" to "+id+"\n");
			destruct(who);
			return 1;
		}
    }
}
int go_paimai(string id,string name,int money,int num,int m)
{
	m+=1;
	command("chat  "+id+" 出价 "+chinese_number(money)+"两银子 购入 "+NOR+name+HIW+" 的所有权，第"+chinese_number(m)+"次");
	if (!(m==3))
		call_out("go_paimai",20,id,name,money,num,m);
	else
		call_out("finish_paimai",5,num,1);	
}
int do_paimailist()
{
	int i;
	
	for(i=query("number")+1;;i++)
	{
		if (query("lpaimai/" + sprintf("%d", i))==1)
		{
			printf("%-10s： 底价 %-3d 两银子 \n",query("npaimai/" + sprintf("%d", i)),query("vpaimai/" + sprintf("%d", i)));
		}
		else
			return 1;
	}
	return 1;
}
int do_yao()
{
	mapping fpaimai,vpaimai,ipaimai,npaimai,lpaimai,spaimai;
	string* terms;
	string id;
	object ob;
	int i;

	fpaimai = query("fpaimai");
	vpaimai = query("vpaimai");
	ipaimai = query("ipaimai");
	npaimai = query("npaimai");
	lpaimai = query("lpaimai");
	spaimai = query("spaimai");
	
	if( mapp(fpaimai) &&  sizeof(fpaimai) )
	{
		terms=keys(fpaimai);
	
		for(i=0;i<sizeof(terms);i++)
		{
			if (ipaimai[terms[i]]==this_player()->query("id") && lpaimai[terms[i]]==0)
			{
				ob=new(fpaimai[terms[i]]);
				if (spaimai[terms[i]]>0)
					ob->set_temp("sale_price",spaimai[terms[i]]);
				ob->move(this_player());
				ipaimai[terms[i]]="paimai shi";
				message_vision(CYN+"拍卖师将"+NOR+npaimai[terms[i]]+CYN+"交给$N。\n", this_player(),this_object());
				return 1;
			}
		}
	}
	tell_object(this_player(),"这里没有属于你的物品。\n");
	return 1;
}
int delete_ob(int num)
{
	delete("npaimai/"+sprintf("%d",num));
	delete("ipaimai/"+sprintf("%d",num));
	delete("vpaimai/"+sprintf("%d",num));
	delete("lpaimai/"+sprintf("%d",num));
	delete("fpaimai/"+sprintf("%d",num));
	delete("spaimai/"+sprintf("%d",num));
	
	return 1;
}


        