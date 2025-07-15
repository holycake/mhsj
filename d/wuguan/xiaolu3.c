//Cracked by Roath
// xiaolu3.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小路"); 
	set("long",@LONG
这是一条用鹅卵石砌成的小路。熙熙攘攘的人们和你擦肩
而过，有的挑着水，有的班着东西。东面是一个柴房，不断有
柴火抱进抱出。 
LONG);
	
	set("exits",([
		"north" : __DIR__"xiaolu2",
		"south" : __DIR__"xiaolu4",
		"east" : __DIR__"chaifang",
		])); 
	
	set("no_fight",1);

    setup(); 
} 
