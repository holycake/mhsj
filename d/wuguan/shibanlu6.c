//Cracked by Roath
// shibanlu6.c
// written by kittt

#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "石板路"); 
	set("long",@LONG
这是一条已经被人走得光溜溜的青石板路。你脚下一滑，
差点摔了一交。西边马房不时传来嘶嘶的马叫声，北面是一条
小径，南面的小路通向休息室。
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing4",
		"east" : __DIR__"shibanlu4",
		"west" : __DIR__"mafang",
		"south" : __DIR__"xiaojing5", 
		])); 
	set("no_fight",1);
	
	setup(); 
} 

int valid_leave(object ob, string dir)
{
	if(!JOB_OB("wuguan")->wrong_way(ob,"shibanlu6",dir))
		return notify_fail("还是先回去再要杯茶吧。\n");
	
	return ::valid_leave(ob, dir);
}