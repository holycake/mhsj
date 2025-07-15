//Cracked by Roath
// xiaolu2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小路"); 
	set("long",@LONG
这是一条用鹅卵石砌成的小路。熙熙攘攘的人们和你擦肩
而过，有的挑着水，有的班着东西。东面有一个水房。 
LONG);
	
	set("exits",([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"xiaolu3",
		"east" : __DIR__"shuifang",
		 ])); 
	set("no_fight",1);
	
	setup(); 
} 

int valid_leave(object ob, string dir)
{
	if(present("tong",ob)&&dir=="north")
		return notify_fail("怎么？连个水桶你也想偷？\n");
	
	return ::valid_leave(ob, dir);
}
