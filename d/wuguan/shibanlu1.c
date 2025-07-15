//Cracked by Roath
// shibanlu1.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "石板路"); 
	set("long",@LONG
这是一条已经被人走得光溜溜的青石板路，路两侧长满了
青草。西面是武馆大院，南面就是武馆的帐房了。
LONG);
	
	set("exits",([
		"west" : __DIR__"dayuan",
		"east" : __DIR__"shibanlu3",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
