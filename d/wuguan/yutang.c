//Cracked by Roath
// yuetang.c
//written by kittt
//modity by yfengf

#include <ansi.h>

inherit ROOM; 

int do_diaoyu(string arg);

void create() 
{
	set("short", "鱼塘"); 
	set("long",@LONG
你来到了一个鱼塘边。塘里的鲤鱼不停的串来串去，泛起
阵阵碧波。旁边好几个人正在垂钓，你不敢打扰，站在一旁静
静地看。      
LONG);

	set("exits",([
		"west" : __DIR__"xiaolu4",
		])); 
	set("no_fight",1);
	
	setup(); 
}

void init()
{
	add_action("do_fishing","diao");
} 

int do_fishing(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_diaoyu(ob,arg);
}