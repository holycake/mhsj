//Cracked by Roath
// shufang.c
//written by kittt

#include <ansi.h>

inherit ROOM; 
void init();
int do_zhengli(string arg);
int do_ca(string arg);
int do_fan(string arg);
int do_si(string arg);

void create() 
{
	set("short", "书房"); 
	set("long",@LONG
这里是馆主读书写字的地方，桌上规规矩矩地摆放着文房
四宝。旁边是一个大书架，放满了书。你翻了翻，没有你想要
的秘籍，倒是一方小印(seal)有点意思。墙上书云：学海无涯 。   
LONG);

	set("exits",([
		"east" : __DIR__"livingroom",
		])); 
	set("item_desc", ([
		"seal" : "你翻过来一看，上面歪歪扭扭地刻着“辣块妈妈”\n", 
		]));
	set("book",([
		"qianzw":1,
		"quanpu":2,
		"strike_book":2,
		]));
	set("no_fight",1);
	
	setup(); 
} 

void init()
{
	add_action("do_zhengli","zhengli");
	add_action("do_ca","ca");
	add_action("do_fan","fan");
	add_action("do_si","si");
}

int do_zhengli(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_zhengli(ob,arg);	
}

int do_ca(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_cashujia(ob,arg);
}

int do_fan(string arg)
{
	object objBook;
	object ob=this_player();
	
	if(!arg || (arg!="书架"))
		return notify_fail("你翻什么？\n");
	if(!ob->query_temp("wuguan/kungfu"))
		return notify_fail("你在这里瞎翻什么？弄得乱七八糟的！\n");
	switch(random(4))
	{
		case 0:
			if(!query("book/quanpu"))
				return notify_fail("你想找的书已经被人拿走了。\n");
			add("book/quanpu",-1);
			objBook=new(__DIR__"obj/quanpu");
			objBook->move(ob);
			message_vision("$N翻了半天，终于找到一"+objBook->query("unit")+objBook->name()+"。\n",ob);
			ob->receive_damage("jingli",50);
			ob->delete_temp("wuguan/kungfu");
			break;
		case 1:
			if(!query("book/strike_book"))
				return notify_fail("你想找的书已经被人拿走了。\n");
			add("book/strike_book",-1);
			objBook=new(__DIR__"obj/strike_book");
			objBook->move(ob);
			message_vision("$N翻了半天，终于找到一"+objBook->query("unit")+objBook->name()+"。\n",ob);
			ob->receive_damage("jingli",50);
			ob->delete_temp("wuguan/kungfu");
			break;
		default:
			message_vision("$N瞎翻了半天，结果什么也没有找到。\n",ob);
			ob->receive_damage("jingli",80);
			break;
	}
	return 1;
}

int do_si(string arg)
{
	object objBook;
	object ob=this_player();
	
	if(!arg || (arg!="seal"))
		return notify_fail("你要撕什么？\n");
	if(!ob->query_temp("wuguan/zixue"))
	{
		message_vision(CYN"$N伸出手撕开小印......\n"NOR,ob);
		message_vision(HIY"突然，一道金光闪过，$N“啊”的一声大叫！！\n"NOR,ob);
		ob->unconcious();
		return 1;
	}
	
	if(!query("book/qianzw"))
		return notify_fail("你正要上前去撕开小印，结果沮丧的发现，小印已经被人撕开了。\n");
	message_vision(CYN"$N慢慢地走上前去，轻轻地撕开小印.....\n"NOR,ob);
	if(random(10))
	{
		tell_object(ob,HIR"恍惚中，你似乎感到空中传来一阵声音：大胆毛贼！想改什么！？\n"NOR);
		message_vision(HIB"$N吓了一跳，向后退去，打消了念头。\n"NOR,ob);
		ob->delete_temp("wuguan/zixue");
		return 1;
	}
	add("book/qianzw",-1);
	objBook=new("/d/obj/book/qian");
	objBook->move(environment(ob));
	ob->receive_damage("jingli",100);
	ob->delete_temp("wuguan/zixue");
	message_vision(HIW"只听“啪”的一声，弹出一本书来。\n"NOR,ob);
	return 1;
}
	