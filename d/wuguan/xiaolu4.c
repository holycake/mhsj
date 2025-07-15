//Cracked by Roath
// xiaolu4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小路"); 
	set("long",@LONG
这是一条用鹅卵石砌成的小路。熙熙攘攘的人们和你擦肩
而过，有的挑着水，有的班着东西。南面通向一块菜地，东面
是一个鱼塘。 
LONG);

	set("exits",([
		"north" : __DIR__"xiaolu3",
		"south" : __DIR__"caidi",
		"east" : __DIR__"yutang", 
		])); 
	set("no_fight",1);
	
	setup(); 
} 
