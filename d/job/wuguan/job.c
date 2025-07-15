//Cracked by Roath
// job.c 武馆任务

#include <ansi.h>
int ask_job(object ob);
int give_up(object ob);
int give_gifts(object ob);
int real_give_gifts(object ob);

mapping *jobs = ({
	([	"job_type":		"wuguan",
		"job":			"钓鱼",
		"bonus":		50,
		"exp":			70,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"东方博玉对你说道：厨房的王厨子需要一条鱼，你到池塘去
钓一条鱼"HIY"(diao 鱼)"HIC"送到王厨子那里。\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"生火",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"东方博玉对你说道：厨房的火工今天病了，你去柴房劈些柴"HIY"
(pi 柴)"HIC"，然后拿着干柴到厨房去生火"HIY"(sheng 火)"HIC"。\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"扫大院",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"东方博玉对你说道：大院里面堆积了不少的树叶，你去帮着
打扫"HIY"(sao 大院)"HIC"一下。\n"NOR
	]),
/*
	([	"job_type":		"wuguan",
		"job":			"倒茶",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"东方博玉对你说道：你来得正好，这里人手不够，你去找小
红要杯茶"HIY"(ask xiao hong about tea)"HIC"，拿到客厅去，放到桌子
上"HIY"(fang 茶)"HIC"。\n"NOR
	]),
*/
	([	"job_type":		"wuguan",
		"job":			"整理书架",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"meony":		5,
		"msg":			
HIC"东方博玉对你说道：你去整理一下书架"HIY"(zhengli 书架)"HIC"，书
房已经好久没人收拾了，可能乱的不行了,别忘了，整完了
把他再擦干净"HIY"(ca 书架)"HIC"。\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"除草",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"东方博玉对你说道：后院菜地杂草丛生，你若有心，去将菜
地里的杂草除一下吧"HIY"(chu  草)"HIC"。\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"浇水",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"东方博玉对你说道：后院菜地长势不太好，好像是缺水的样子，
先到水房打桶水"HIY"(da 水)"HIC"，然后去后院菜地浇水"HIY"(jiao 水)"HIC"。\n"NOR
	]),
	});

// 要任务
int ask_job(object ob)
{
	mapping		job;

	if(!ob->query("wuguan/join"))  //不是武馆成员
	{
		message_vision(
CYN "东方博玉受宠若惊："+RANK_D->query_respect(ob)+"不是本武馆的人，“效劳”二字严重了。\n" NOR,ob);
		return 1;
	}
	
	// 是武馆成员
	if(ob->query_temp("wuguan/job"))  //身上有job
	{
		tell_room(ob,CYN "东方博玉皱了皱眉：你还是先把手头上的活干完再说吧。\n" NOR);
				return 1;
	}
	else  //not job
	{
	// 分配新job
		job=jobs[random(sizeof(jobs))];
		ob->set_temp("wuguan/job",job);
		tell_object(ob,job["msg"]);
		return 1;
	}
}

// 放弃任务
int give_up(object ob)
{
	mapping job;

	if(!(job=ob->query_temp("wuguan/job")))
	{
		tell_object(ob,CYN"东方博玉说道：你有没领任务，胡喊什么？\n"NOR);
		return 1;
	}
	
	ob->delete_temp("wuguan");
	tell_object(ob,CYN"东方博玉说道：既然这次干不了也没关系，下次再努力吧。\n"NOR);
	ob->add("combat_exp",-((int)job["bonus"]/10+random(job["exp"]/10)));
	if(ob->query("combat_exp")<0)
		ob->set("combat_exp",0);
	return 1;	
}

// 发工具
int give_tool(object ob,object npc)
{
	mapping job;
	object objTool;
	
   seteuid(getuid());
	if(!(job=ob->query_temp("wuguan/job")))
	{
		message_vision(
"孙管事对着$N说道：你什么任务都没有，到这里来骗工具么？\n",ob);
		return 1;
	}
	if(ob->query_temp("wuguan/tool"))
	{
		tell_object(ob,
"孙管事说道：你先把上回借的工具还了再说。\n");
		return 1;
	}
		
	switch(job["job"])
	{
		case	"钓鱼":
			objTool=new(__DIR__"obj/yugan");
			break;
		case	"生火":
			objTool=new(__DIR__"obj/chaidao");
			break;
		case	"扫大院":
			objTool=new(__DIR__"obj/saozhou");
			break;
		case	"整理书架":
			objTool=new(__DIR__"obj/mabu");
			break;
		case	"除草":
			objTool=new(__DIR__"obj/chutou");
			break;
		case	"浇水":
			objTool=new(__DIR__"obj/piao");
			break;
		default:
			message_vision(CYN
"孙管事说道：你现在的工作，不需要什么工具。\n"NOR,ob);
		return 1;
		break;
	}
	
	objTool->move(ob);
	ob->set_temp("wuguan/tool",objTool->query("id"));
	message_vision("孙管事说道：这是"+objTool->query("name")+"你拿好，记着用完了还回来。\n",ob);
	tell_object(ob,"你得到一"+objTool->query("unit")+objTool->query("name")+"。\n");
	return 1;
}

// 接收工具
int accept_tool(object npc,object ob,object obj)
{
	if(!ob->query_temp("wuguan/tool"))
	{
		message_vision(
"$n对$N笑道：怎么？贿赂我？我可不会被你腐蚀的。\n",ob,npc);
		return 0;
	}
	if(interactive(obj))
		return notify_fail("你想干什么？贩卖人口？\n");
	if(obj->query("id")!=ob->query_temp("wuguan/tool"))
		return notify_fail("这东西是你刚借的么？\n");
	
	message_vision(
"$n拍拍$N的头，嘻嘻笑道：好样的。\n",ob,npc);
	ob->delete_temp("wuguan/tool");
	call_out("destruct_tool",1,obj);
	return 1;
}

void destruct_tool(object obj)
{
	destruct(obj);
	return;
}

// 奖励
int give_gifts(object ob)
{
        ob->set_temp("wuguan/job_finish",1);
        return 1;
}        
int real_give_gifts(object ob)
{
	int exp,pot,silv;
	mapping job=ob->query_temp("wuguan/job");
	
	ob->add("combat_exp",(exp=(int)job["bonus"]+random(job["exp"])));
	ob->add("potential",(pot=(int)job["bonus"]/2+random(job["pot"])));
	MONEY_D->pay_player(ob,(silv=(int)job["bonus"]/10+random(job["money"]))*100);
	tell_object(ob,CYN"东方博玉拍了拍你的肩膀:干的好,这是给你的赏钱!\n"NOR);
	tell_object(ob,
HIY"恭喜你获得"+chinese_number(exp)+"点实战经验，"+chinese_number(pot)+"点潜能!\n"NOR);
        tell_object(ob,"东方博玉给你一些银子.\n");
	ob->delete_temp("wuguan/job");
	ob->set_temp("wuguan/job_finish",0);
	return 1;
}
	
	
// 扫大院
int job_saodayuan(object ob,string arg)
{
	int exp,pot,silv;
	mapping job;

	if(!arg||(arg!="大院"))
	{
		return notify_fail("你想扫什么？\n");
	}	
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("大院现在挺干净的，不用你扫了。\n");
	if(job["job"]!="扫大院")
		return notify_fail("你现在的工作不是扫大院，先把手头的活干完再说吧。\n");
	if(!present("sao zhou",ob))
		return notify_fail("你拿什么扫地？用衣服么？\n");
	if(ob->is_busy())
		return notify_fail("你扫得快，不一定扫得干净，慢慢来吧。\n");
	if(ob->query("kee")<10)
		return notify_fail("你的精力现在无法集中，歇会再扫吧。\n");
	
	ob->start_busy(1);
	if(ob->query_temp("wuguan/saodayuan")<20)
	{
		ob->add_temp("wuguan/saodayuan",1);
		ob->receive_damage("kee",5);
		return notify_fail("你拿着扫帚，一下一下的扫起来。\n");
	}
	if(random(100) > 80)
	{
		message_vision(
"$N看起来平时不太劳动，居然把院子越扫越脏了。\n",ob);
		ob->receive_damage("kee",5);
		return 1;
	}
			
	message_vision(
"$N挥舞着扫帚，干的热火朝天，不一会，大院被扫的干干净净。\n",ob);
	ob->receive_damage("kee",10);
	ob->delete_temp("wuguan/saodayuan");
	return give_gifts(ob);
}

// 钓鱼
int job_diaoyu(object ob,string arg)
{
	mapping		job;

	if(!(job=ob->query_temp("wuguan/job")))  //没有job
	{
		tell_object(ob,CYN "小鱼告诉你：嗨，你没有经过总管的同意，在这里钓鱼是要罚钱的。\n" NOR);
		message_vision(CYN "$N口吐白沫，向后倒飞了出去。\n" NOR ,ob);
		return 1;
	}
	if((job["job"])!="钓鱼") //job 不是钓鱼
	{
		tell_object(ob,"你还是先把手头的活干完再说吧。\n");
		return 1;
	}
	//钓鱼job
	if(!arg)
		return notify_fail("你想钓什么？\n");
	if(arg!= "鱼")
		return notify_fail("你要钓的东西，这里没有。\n");
	if(ob->is_busy())
		return notify_fail("钓鱼要有耐心，象你这样急急忙忙，怎么钓的着鱼。\n");
	if(ob->query_temp("wuguan/fishing"))
		return notify_fail("你不是正钓着呢么？别急！\n");
	if(!present("yu gan",ob))
		return notify_fail("你没有鱼竿怎么钓鱼？\n");
	if(ob->query("sen") < 20)
		return notify_fail("你精神不太好，怎么钓鱼？\n");
	if(ob->query_temp("wuguan/fish"))
		return notify_fail("别太贪了，有一条鱼就够了。\n");
	
	message_vision("$N拿出一根鱼竿，静静地坐了下来。\n",ob);
	ob->start_busy(1);
	ob->set_temp("wuguan/fishing",1);
	call_out("end_fishing",30,ob);
	return 1;
}

int end_fishing(object ob)
{
	object obj;
	
	ob->delete_temp("wuguan/fishing");
	if(random(100) < 30)
	{
		ob->receive_damage("sen",10);
		tell_object(ob,"你费了半天劲，却没钓着一条鱼。\n");
		message_vision("$N显得满脸沮丧。\n",ob);
		return 1;
	}
	
	obj=new(__DIR__"obj/fish");
	obj->move(ob);
	ob->receive_damage("sen",15);
	ob->set_temp("wuguan/fish",1);
	tell_object(ob,"你好像觉得鱼标在下沉，你一拉鱼竿，果然鱼钩上挂着一条鱼。\n");
	message_vision(CYN"$N高兴的跳了起来。\n"NOR,ob);
	return 1;
}

int give_fish(object npc,object ob,object obj)
{
	mapping job;
		
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail(CYN"王厨子满脸疑惑：你给我这玩艺干什么？\n"NOR);
	if(job["job"]!="钓鱼")
		return notify_fail(CYN"王厨子说道：我现在不需要这东西，你自己留着用吧。\n"NOR);
	if(obj->query("id")!="li yu")
		return notify_fail(CYN"王厨子说道:这是什么东西呀?\n"NOR);
	
	ob->delete_temp("wuguan/fish");
	call_out("destruct_fish",1,obj);
	message_vision(
CYN"$n笑嘻嘻地对$N说：你如此精明能干，他日定有所成。\n"NOR,ob,npc);
	return give_gifts(ob);
}

void destruct_fish(object obj)
{
	if(objectp(obj))
		destruct(obj);
	return;
}

// 打水
int job_dashui(object ob,string arg)
{
	mapping 	job;
	
	if(!arg||(arg!="水"))
		return notify_fail("你想打什么？\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("你现在不能在这里打水。\n");
	if(job["job"]!="浇水")
		return notify_fail("你先忙你的事去吧。\n");
	if(!present("tong",ob))
		return notify_fail("连桶都没了，你拿什么提水？\n");
	
	message_vision("$N走到井边，费力的摇着辘轳，终于打起了一桶水。\n",ob);
	ob->receive_damage("kee",10);
	ob->start_busy(3);
	return 1;
}

// 浇水
int job_jiaoshui(object ob,string arg)
{
	int exp,pot,silv;
	mapping job;

	if(!arg||arg!="水")
		return notify_fail("你想浇什么？\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("这里的菜水分充足，你瞎浇什么？\n");
	if(job["job"]!="浇水")
		return notify_fail("你现在的工作不是浇水，先把手头的活干完再说吧。\n");
	if(!present("tong",ob))
		return notify_fail("你没有提水桶，怎么浇水？\n");
	if(!present("piao",ob))
		return notify_fail("你没有瓢，拿什么浇水？\n");
	if(ob->is_busy())
		return notify_fail("慢慢来，别太急。 \n");
	if(ob->query("kee")<10)
		return notify_fail("你现在精力不好，别累昏了。\n");
		
	ob->start_busy(1);
	if(ob->query_temp("wuguan/jiaoshui")>20)
	{
		if(random(100)>20)
		{
			ob->delete_temp("wuguan/jiaoshui");
			message_vision("$N将桶里的水浇完，觉得园子里的菜长得更旺盛了。\n",ob);
			return give_gifts(ob);
		}
		
		return notify_fail("你拿着瓢随便浇了几下，看起来漫不经心。\n");
	}
	
	ob->add_temp("wuguan/jiaoshui",1);
	ob->receive_damage("kee",3);
	return notify_fail("你舀出一瓢水，浇到菜上。\n");
}

// 除草
int job_chucao(object ob,string arg)
{

	int exp,pot,silv;
	mapping job;

	if(!arg||(arg!="草"))
		return notify_fail("你想锄什么？\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("这没杂草，不用你锄了。\n");
	if(job["job"]!="除草")
		return notify_fail("你现在的工作不是除草，先把手头的活干完再说吧。\n");
	if(!present("chu tou",ob))
		return notify_fail("你没锄头，除什么草？\n");
	if(ob->is_busy())
		return notify_fail("别干那么快，身体可是本钱。\n");
	if(ob->query("kee")<10)
		return notify_fail("快昏了，快昏了，不能再干了。\n");
	
	ob->start_busy(1);
	if(ob->query_temp("wuguan/chucao")>20)
	{
		if(random(100) > 20)
		{
			ob->delete_temp("wuguan/chucao");
			message_vision(CYN"经过半天的努力，$N终于将菜地里的杂草除干净了。\n"NOR,ob);
			return give_gifts(ob);
		}
		
		return notify_fail("你一不留神，把好好的菜连根刨了出来。\n");
	}
	
	ob->add_temp("wuguan/chucao",1);
	ob->receive_damage("kee",3);
	return notify_fail("你轮起锄头，一下一下地除了起来。\n");
}

// 劈柴
int job_pichai(object ob,string arg)
{
	object obj;
	
	if(!arg||(arg!="柴"))
		return notify_fail("你想劈什么？\n");
	if(!present("chai dao",ob))
		return notify_fail("你拿什么劈柴？用手撕么？\n");
	if(ob->query("kee") < 10)
		return notify_fail("你现在精力不够，强行劈柴，可能会有生命危险。\n");
	if(ob->is_busy())
		return notify_fail("以你现在的刀法，劈得太快可能会要了自己的小命。\n");
	
	message_vision("$N放正一块木头。\n",ob);
	if(random(100) < 20)
	{
		message_vision("$N一刀劈了下去，不过由于手法太差，查点劈着自己的脚。\n",ob);
		ob->receive_damage("kee",10);
		ob->receive_damage("sen",10);
		return 1;
	}
	
	ob->add_temp("wuguan/pichai",1);
	message_vision(
			"$N将木块放正，高举柴刀，大喝一声“开”，木块“咔”的一声被劈开了。\n",ob);
	obj=new(__DIR__"obj/chai");
	obj->move(environment(ob));
	ob->start_busy(1);
	ob->receive_damage("kee",5);
	return 1;
}

// 生火
int job_shenghuo(object ob,string arg)
{
	object objChai;
	mapping job;
	
	if(!arg||(arg!="火"))
		return notify_fail("你想干什么？\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("你在这里干什么？想放火么！！！。\n");
	if(job["job"]!="生火")
		return notify_fail("现在又没让你生火，你到这里生什么火！！\n");
	if(ob->is_busy())
		return notify_fail("一下子把柴都添进去，会把火压灭的。\n");
	if(!(objChai=present("chai",ob)))
		return notify_fail("你都没有柴，还想生火，疯了是不是。\n");
	if(ob->query("kee")<10)
		return notify_fail("你现在精力不能集中，小心把武馆烧着了。\n");
	if(ob->query_temp("wuguan/fire"))
		return notify_fail("你这不是正生着火呢么？\n");
	if(!ob->query_temp("wuguan/pichai"))	
		return notify_fail("你好像没有去劈柴，哪来的柴火？\n");
	
	ob->add_temp("wuguan/pichai",-1);	
	destruct(objChai);
	ob->start_busy(3);
	ob->set_temp("wuguan/fire",1);
	call_out("over_sheng",3,ob);
	message_vision(
"$N拿出一根柴火在一旁引着，放到炉子里。\n",ob);
    return 1;
}

int over_sheng(object ob)
{
	ob->delete_temp("wuguan/fire");
	if(random(100)<65)
	{
	 	ob->receive_damage("kee",5);
	 	message_vision(
"$N费了半天劲，脸被烟熏的像个大花猫，但却没把火生着。\n",ob);
        return 1;
	}
	
	message_vision(
"但见"+HIR"火苗"NOR+"越生越旺，$N拿起吹火棍加紧吹了几下，终于把火生着了。\n",ob);
	ob->receive_damage("kee",10);
	return give_gifts(ob);
}

// 整理书架
int job_zhengli(object ob,string arg)
{
	mapping 	job;
	
	if(!arg||(arg!="书架"))
		return notify_fail("你要整理什么？\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("书架现在不需要你整理。\n");
	if(job["job"]!="整理书架")
		return notify_fail("你现在的工作不是整理书架，先把手头的活干完再说吧。\n");
	if(ob->query_temp("wuguan/cashujia"))
		return notify_fail("书已经整理好了。\n");
	if(ob->query("kee")<10)
		return notify_fail("由于你的精力不能集中，所以书架越整越乱。\n");
	if(ob->is_busy())
		return notify_fail("这是细活，要慢慢来。\n");
	
	ob->add_temp("wuguan/zhenglishujia",1);
	if(ob->query_temp("wuguan/zhenglishujia")<15)
	{
		ob->add_temp("zhenglishujia",1);
		ob->start_busy(1);
		ob->receive_damage("kee",5);
		return notify_fail("你将书一本一本分门别类的放好。\n");
	}
	
	ob->receive_damage("kee",8);
	ob->delete_temp("wuguan/zhenglishujia");
	ob->set_temp("wuguan/cashujia",1);
	tell_object(ob,"你将书上的灰尘拍掉，觉得现在应该把书架擦干净了。\n");
	return 1;
}

// 擦书架
int job_cashujia(object ob,string arg)
{
	mapping job;

	if(!arg||(arg!="书架"))
		return notify_fail("你想擦什么？\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("书架现在挺干净的，不用你擦了。\n");
	if(job["job"]!="整理书架")
		return notify_fail("你现在的工作不是擦书架，先把手头的活干完再说吧。\n");
	if(!present("ma bu",ob))
		return notify_fail("你的热心让人感动，可是你的衣服也不干净，还是找块抹布来擦吧？\n");
	if(!ob->query_temp("wuguan/cashujia"))
		return notify_fail("书架里的书还放个乱七八糟，你擦个什么劲？\n");
	if(ob->query("kee")<10)
		return notify_fail("你无法集中精力把书架擦干净。\n");
	if(ob->is_busy())
		return notify_fail("擦那么快干什么？一点都不用心。\n");
	
	if(ob->query_temp("wuguan/cashujia")<10)
	{
		ob->start_busy(1);
		ob->add_temp("wuguan/cashujia",1);
		ob->receive_damage("kee",5);
		return notify_fail("你拿起抹布，一下一下的擦着书架。\n");
	}
	
	message_vision(
"$N费了半天劲，终于将书架擦得干干净净。$N将整好的书整整齐齐的摆放在书架里。\n",ob);
	ob->receive_damage("kee",8);
	ob->delete_temp("wuguan/cashujia");
	return give_gifts(ob);
}

// 要茶
int job_asktea(object ob)
{
	mapping job;
	object objTea;
	
	if(!(job=ob->query_temp("wuguan/job")))
	{
		message_vision(CYN"小红说道：没有总管吩咐，我可不敢给你上好的茶。\n"NOR,ob);
		return 1;
	}
	if(job["job"]!="倒茶")
	{
		message_vision(CYN"小红眼泪汪汪：你这般劳累，我很是心痛，可没有总管吩咐，我可不敢给你上好的茶。\n"NOR,ob);
		return 1;
	}
	if(ob->query("kee")<10)
	{
		message_vision(CYN"小红对$N说道：你太劳累了，就算端了茶，也会洒的，你先休息一下吧。\n"NOR,ob);
		return 1;
	}
	if(present("wulong tea",environment(ob)))
	{
		message_vision(CYN"小红说道：你瞎啦，没看见地上有么？\n"NOR,ob);
		return 1;
	}
	if(present("wulong tea",ob))
	{
		message_vision(CYN"小红邹了邹眉，说道：你怎地如此贪心，你不是已经有了么？\n"NOR,ob);
		return 1;
	}
	
	message_vision(
CYN"$N深深地作了一揖，恭敬的说道：咱们武馆来了客人，总管大人见你繁忙，让我来此替姑娘送茶。\n"NOR,ob);
	message_vision(
CYN"小红抿嘴一笑：那就有劳你啦，给，这是刚沏好的洞顶乌龙，快拿去吧。\n"NOR,ob);
	ob->receive_damage("kee",5);
	ob->set_temp("wuguan/tea",1);
	ob->delete_temp("wuguan/wrong");
	objTea=new(__DIR__"obj/wulongtea");
	objTea->move(ob);
	tell_object(ob,"你获得一杯"+YEL"乌龙茶"NOR+"。\n");
	return 1;	
}

int wrong_way(object ob,string room,string dir)
{
	mapping path=([
				"huayuan":		"east",
				"xiaojing5":	"north",
				"shibanlu6":	"east",
				"dayuan":		"southup",
				]);

	object objTea;
	
	if(ob->query_temp("wuguan/wrong") && dir==path[room])
		return 0;
	if(ob->query_temp("wuguan/tea"))
	{
		if(!ob->query_temp("wuguan/path/"+room))
		{
			if(random(100)<50)
			{
				message_vision(HIR"$N一个没站稳，滑了一跤，结果把乌龙茶摔到了地上。\n"NOR,ob);
				if(objTea=present("wulong tea",ob))
					destruct(objTea);
				ob->receive_damage("kee",5);
				ob->delete_temp("wuguan/tea");
				ob->set_temp("wuguan/wrong",1);//限定走路方向
				ob->set_temp("wuguan/path/"+room,1);
				if(dir==path[room])
					return 0;
			}
		}
	}
	
	return 1;
}

// 放茶
int job_fangcha(object ob,string arg)
{
	mapping 	job;
	object objTea;
		
	if(!arg||(arg!="茶"))
		return notify_fail("你想放什么?\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("你不能把东西放到这里。\n");
	if(job["job"]!="倒茶")
		return notify_fail("你先忙你的事去吧，这里不需要你。\n");
	if(!(objTea=present("wulong tea",ob)))
		return notify_fail("你没有乌龙茶，跑着来干什么？\n");
	
	ob->delete_temp("wuguan/tea");
	ob->delete_temp("wuguan/path");
	if(!objTea->query("value") )
	{
		message_vision(
"东方馆主跑过来,“啪”的扇了$N一记响亮的耳光，骂道：你这不成器的东西，竟敢偷喝，滚吧！\n",ob);
		ob->delete("wuguan");
		ob->receive_damage("sen",50);
		ob->set("kee",1);
		ob->move(CITY_OB("wuguan","schoolhall"));
		destruct(objTea);
		message_vision(
"只见$N连滚带爬的被人踢了出来，摔了个鼻清脸肿。\n",ob);
		return 1;
	}
	
	message_vision("$N恭恭敬敬的将一杯上好的"+YEL"乌龙茶"NOR+"放到桌上。\n",ob);
	destruct(objTea);
	ob->receive_damage("kee",10);
	return give_gifts(ob);
}
