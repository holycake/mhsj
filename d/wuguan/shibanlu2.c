//Cracked by Roath
// shibanlu2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "石板路"); 
	set("long",@LONG
这是一条已经被人走得光溜溜的青石板路，路两侧长满了
青草。东面就是武馆的大院了，南面是武馆自己办的学堂。
LONG);
	
	set("exits",([
//             "south" : __DIR__"xuetang",
		"east" : __DIR__"dayuan",
		"west" : __DIR__"shibanlu4",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
