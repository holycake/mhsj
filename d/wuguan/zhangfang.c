//Cracked by Roath
// zhangfang.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "帐房"); 
	set("long",@LONG
武馆管钱的地方，和外面的钱庄也经常有往来。墙上贴着
四个烫金大字“日近斗金”。一位戴着眼镜的帐房先生正拨打
着算盘，似乎在算着什麽。  
LONG);

	set("exits",([
		"north" : __DIR__"shibanlu1",
		]));
	set("objects", ([
		__DIR__"npc/cuiguanshi":1,
	]));
	set("no_fight",1);

    setup(); 
}