//Cracked by Roath
// liangting1.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "凉亭"); 
	set("long",@LONG
这是一座供人乘凉的凉亭，里面有石桌石凳。你略感腿部
发酸，就跑到凉亭里打了个小盹。西面是一条长廊。 
LONG);

	set("exits",([
		"west" : __DIR__"changlang3",
		"south" : __DIR__"xiaojing1",
		])); 
	set("no_fight",1);

	setup(); 
} 
