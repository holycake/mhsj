//Cracked by Roath
// liangting2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "凉亭"); 
	set("long",@LONG
这是一座供人乘凉的凉亭，里面有石桌石凳。你略感腿部
发酸，就跑到凉亭里打了个小盹。东面是一条长廊。  
LONG);

	set("exits",([
		"east" : __DIR__"changlang4",
		"south" : __DIR__"xiaojing2",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
