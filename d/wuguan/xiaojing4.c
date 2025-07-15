//Cracked by Roath
// xiaojing4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小径"); 
	set("long",@LONG
你走在一条小径上。两旁都是竹林，北面是一座供休息的
凉亭。西边是工具房，南面是一条石板路。 
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing2",
		"south" : __DIR__"shibanlu6",
		"west" : __DIR__"gongjufang",
		])); 
	
	set("no_fight",1);
	
	setup(); 
} 
