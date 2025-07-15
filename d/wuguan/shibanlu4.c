//Cracked by Roath
// shibanlu4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "石板路"); 
	set("long",@LONG
这是一条已经被人走得光溜溜的青石板路，你一不小心踩
上块青苔，摔了个大马趴。北面武馆练武场不时传来嘿嘿的用
力声。
LONG);

	set("exits",([
               "north" : __DIR__"lianwuch2",
		"west" : __DIR__"shibanlu6",
		"east" : __DIR__"shibanlu2",
		])); 
	set("no_fight",1);

	setup(); 

} 
