//Cracked by Roath
// lianwuch2.c
// written by kittt

inherit ROOM;

void init();

int do_tiao(string arg);

void create() 
{
	set("short", "练武场"); 
	set("long",@LONG
这里是武馆的练武场，大家各练各的，有人练剑，有人练
刀，有人练棍，还有人汗流浃背地在一个沙坑(keng)跳进跳出。
旁边的一位教头冷冷地看着，不时说上两句。
LONG);
	
	set("item_desc",([
		"keng":		"一个沙坑，你想跳跳(tiao)看。\n"
		]));
	set("exits",([
		"south" : __DIR__"shibanlu4",
		]));
	set("objects",([
//		__DIR__"npc/liwushi":	1,
		]));
	
	setup(); 
}
 
void init()
{
	add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
	object ob=this_player();
	
	if((!arg)||(arg!="keng"))
		return notify_fail("你要跳什么？\n");
	if(ob->query_skill("dodge",1)>50)
		return notify_fail("别指望跳沙坑能跳出个深不可测。\n");
	ob->improve_skill("dodge", random(3));
	ob->receive_damage("kee",10);
	message_vision("$N在沙坑上跳来跳去。\n",ob);
	return 1;
}