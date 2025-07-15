//Cracked by Roath
// zhulin.c
//written by kittt

#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "竹林"); 
	set("long",@LONG
你走在一片幽静的竹林中，几屡阳光透过竹叶照在你身上
暖洋洋的。空气清新得让你忍不住想打架。西面隐隐约约有去
处。 
LONG);

	set("exits",([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"xiaojing5",
		])); 
		
	setup(); 
} 
