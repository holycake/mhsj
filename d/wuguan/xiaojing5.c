//Cracked by Roath
// xiaojing5.c
//written by kittt

#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "小径"); 
	set("long",@LONG
你走在一条小径上。两旁都是竹林，西面的竹林好像还有
路能走进去。南面是通往休息室的长廊。 
LONG);

	set("exits",([
		"north" : __DIR__"shibanlu6",
		"south" : __DIR__"zoulang",
		"west" : __DIR__"zhulin",
		])); 
	set("no_fight",1);
	
	setup(); 
}

int valid_leave(object ob, string dir)
{
	if(!JOB_OB("wuguan")->wrong_way(ob,"xiaojing5",dir))
		return notify_fail("还是先回去再要杯茶吧。\n");
	
	return ::valid_leave(ob, dir);
}