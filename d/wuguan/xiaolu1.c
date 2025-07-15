//Cracked by Roath
// xiaolu1.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小路"); 
	set("long",@LONG
这是一条用鹅卵石砌成的小路。熙熙攘攘的人们和你擦肩
而过，有的挑着水，有的班着东西。北面是一条石板路。 
LONG);

	set("exits",([
		"north" : __DIR__"shibanlu5",
		"south" : __DIR__"xiaolu2",
		])); 
	set("objects",([
		__DIR__"npc/guanjia" : 1 
		]));
	
	setup(); 
} 
