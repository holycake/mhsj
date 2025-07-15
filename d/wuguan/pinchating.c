//Cracked by Roath
// pinchating.c
// written by kittt
// add by yfengf

inherit ROOM; 

#include <ansi.h>

void create() 
{
	set("short", HIG"品茶亭"NOR); 
	set("long",@LONG
你拨开竹叶，一座亭子映入眼帘，亭额上大书“品茶亭”
三个字。亭内凉气袭人，确为品茶的好地方。向南能看到一座
小桥。
LONG);

	set("exits",([
		"north" : __DIR__"huayuan",
		"south" : __DIR__"bridge",
		])); 
	set("no_fight",1);
	set("objects",([
		__DIR__"obj/tea" : 	2,
		__DIR__"npc/xiaohong":	1,	
		]));
	replace_program(ROOM);
	
	setup(); 
} 
