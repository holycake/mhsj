//Cracked by Roath
// wuguangate.c
//written by kittt

#define YANGZHOU			"yangzhou"
#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "扬州武馆大门"); 
	set("long",@LONG
这是一间气势宏大的武馆，大门虚掩着，门上悬了一块大
匾(bian)门口蹲踞着两个威猛的石狮子，武馆里传来一阵阵练
武的声音。据说这个武馆已经有上百年的历史了，专门收留一
些初入江湖的新手，让他们学习一些基本的武功以后好行走江
湖。      
LONG);

	set("exits",([
		"north" : CITY_OB(YANGZHOU,"xidajie2"),
		"south" : __DIR__"qianyuan",
		])); 
	
	set("objects", ([
                __DIR__"npc/menwei" : 1,
		__DIR__"npc/xiaosi" : 1,
		]));
		
	set("item_desc",(["bian":HIY "
	
	
       ##############################
       ####                      ####
       ####      扬 州 武 馆     ####
       ####                      ####
       ##############################\n\n" NOR]));
             
        setup(); 
	
} 

int valid_leave(object me, string dir)
{
	if (me->query("combat_exp")>20000 && dir=="south")
		return notify_fail("以你现在的武功根基，不要在进去浪费青春了。\n");

	return ::valid_leave(me, dir);
}
