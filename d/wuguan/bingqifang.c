//Cracked by Roath
// bingqifang.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "兵器房"); 
	set("long",@LONG
这是武馆的兵器房，刀,枪,剑,棍,斧等各式各样的武器整整齐
齐地摆放在架子上。你刚要伸手拿条枪来试试，突然一把钢刀从
架子上掉下来，差点没把你小命要了。   
LONG);

	set("exits",([
		"west" : __DIR__"xiaojing3",
		])); 
	set("objects",([
		__DIR__"obj/blade":		1,
		__DIR__"obj/changjian":	1,
		__DIR__"obj/gun":		1,
		]));
	
	setup();
} 
