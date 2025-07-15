//Cracked by Roath
// huayuan.c
// written by kittt

#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "花园"); 
	set("long",@LONG	  
你钻出竹林，犹如来到了一片世外桃源。各种鲜花开得到
处都是，小鸟在站在枝头轻快地歌唱。你不禁沉浸在其中不愿
离开。北面是一座假山，南边不知通到哪儿。        
LONG);

	set("exits",([
		"north" : __DIR__"jiashan",
		"south" : __DIR__"pinchating",
		"east" : __DIR__"zhulin",
		])); 
	set("no_fight",1);

	setup(); 

} 

int valid_leave(object ob, string dir)
{
	if(!JOB_OB("wuguan")->wrong_way(ob,"huayuan",dir))
		return notify_fail("还是先回去再要杯茶吧。\n");
	
	return ::valid_leave(ob, dir);
}