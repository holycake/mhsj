//Cracked by Roath
// lianwuch1.c
// written by kittt

inherit ROOM; 
void init();
int do_da(string arg);
int do_yao(string arg);

void create() 
{
	set("short", "练武场"); 
	set("long",@LONG
这里是武馆的练武场，武场中间摆着几个木桩(muzhuang)，
有几个人在聚精会神地打着。也有人在互相切磋，看得你手痒
痒的。旁边还有个教头在指点他们。    
LONG);

	set("exits",([
		"south" : __DIR__"shibanlu3",
		])); 
	set("item_desc",([
		"muzhuang":		"这是练武用的木桩，可以打(da)和摇(yao)。\n"
		]));
	set("objects",([
//		__DIR__"npc/zhaowushi":1,
		]));
		
	setup(); 
} 

void init()
{
	add_action("do_da","da");
	add_action("do_yao","yao");
}

int do_da(string arg)
{
	int pot;
	object ob=this_player();
	
	if((!arg)||(arg!="muzhuang"))
		return notify_fail("你要打什么？\n");
	if(ob->query_skill("unarmed",1)>50)
		return notify_fail("你的拳发十分精湛，打这玩艺已经得不到什么长进。\n");
	
	pot=random(10);
	if(pot)
	{
		ob->improve_skill("unarmed", pot);
		ob->receive_damage("kee",10);
		message_vision("$N扎稳马步，气至丹田，一拳向木桩打去。\n",ob);
		tell_object(ob,"你对「基本拳法」有所了解。\n");
		return 1;
	}
	ob->receive_damgae("kee",5);
	message_vision("$N挥舞着双拳，对着木桩一阵乱砸。\n",ob);
	return notify_fail("你挥舞了半天拳头，什么长进都没有。\n");
}

int do_yao(string arg)
{
	int pot;
	object ob=this_player();
		
	if((!arg)||(arg!="muzhuang"))
		return notify_fail("你要摇什么？\n");
	if(ob->query_skill("parry",1)>50)
		return notify_fail("别指望摇这东西摇出个深不可测。\n");
		
	pot=random(10);
	if(pot)
	{
		message_vision("$N双手抱环，来回地摇着木桩。\n",ob);
		ob->improve_skill("parry",pot);
		ob->receive_damage("kee",10);
		tell_object(ob,"你对「基本招架」有所了解。\n");
		return 1;
	}
	ob->receive_damage("kee",5);
	message_vision("$N抱着木桩乱摇一气，也不知道想干什么。\n",ob);
	return notify_fail("你摇了半天的木桩，好想得不到什么长进。\n");
}