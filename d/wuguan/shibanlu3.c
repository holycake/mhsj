//Cracked by Roath
// shibanlu4.c
// written by kittt

inherit ROOM;

void create() 
{
	set("short", "石板路"); 
	set("long",@LONG
这是一条已经被人走得光溜溜的青石板路，你一不小心踩
上块青苔，摔了个大马趴。北面练武场不时传来嘿嘿的声音，
让你忍不住要去看看。
LONG);
	
	set("exits",([
		"north" : __DIR__"lianwuch1",
		"west" : __DIR__"shibanlu1",
		"east" : __DIR__"shibanlu5",
		])); 
	set("no_fight",1);

	setup(); 
} 
