//Cracked by Roath
// xiaojing2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小径"); 
	set("long",@LONG
你走在一条小径上。两旁都是竹林，南面是一座供休息的
凉亭。
LONG);

	set("exits",([
		"north" : __DIR__"liangting2",
		"south" : __DIR__"xiaojing4",
		])); 
		
	set("no_fight",1);
	
	setup(); 
} 
