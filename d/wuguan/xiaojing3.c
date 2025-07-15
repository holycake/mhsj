//Cracked by Roath
// xiaojing3.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小径"); 
	set("long",@LONG
你走在一条小径上。两旁都是竹林，北面是一座供休息的
凉亭。东边就武馆的兵器房。南面是一条石板路。
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing1",
		"south" : __DIR__"shibanlu5",
		"east" : __DIR__"bingqifang",
		]));
	
 	set("no_fight",1);
 	
 	setup(); 
} 
