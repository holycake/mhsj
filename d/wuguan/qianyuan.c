//Cracked by Roath
// qianyuan.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "前院"); 
	set("long",@LONG
这是扬州武馆的前院，看起来干干净净的很清爽。北面是
武馆的大门。左右两侧是长廊，南面通往武馆的前厅。  
LONG);

	set("exits",([
		"north" : __DIR__"wuguangate",
		"south" : __DIR__"qianting",
		"east" : __DIR__"changlang1",
		"west" : __DIR__"changlang2",
		])); 
	set("objects", ([ 
		__DIR__"npc/jiading" : 2,
		]));
	set("no_clean_up", 0);
	
	setup(); 
	call_other("/clone/board/wuguan_b", "???");
} 