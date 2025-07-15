//Cracked by Roath
// houyuan.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "后院"); 
	set("long",@LONG	
这里是武馆的后院，院中间长了一棵巨大的苍松，这儿很
少有人经过，显得十分清净。一个小丫环正在打扫。南边通向
馆主的卧室，北面是客厅。    
LONG);

	set("exits",([
		"north" : __DIR__"keting",
		"south" : __DIR__"livingroom",
		])); 
	set("objects", ([ 
		__DIR__"npc/yahuan" : 1,
		]));
	set("no_clean_up", 0);
	
	setup(); 
} 
