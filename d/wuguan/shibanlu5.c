//Cracked by Roath
// shibanlu5.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "石板路"); 
	set("long",@LONG
这是一条已经被人走得光溜溜的青石板路。你脚下一滑，
差点摔了一交。东面传来阵阵菜香，北面是一条小径，往西通
向武馆大院。
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing3",
		"west" : __DIR__"shibanlu3",
		"east" : __DIR__"dinningroom",
		"south" : __DIR__"xiaolu1", 
		])); 
	set("no_fight",1);
	
	setup(); 
} 
