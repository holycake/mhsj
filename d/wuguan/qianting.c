//Cracked by Roath
// qianting.c
// written by kittt
// modify by yfengf

#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "前厅"); 
	set("long",@LONG
这里是馆主用来迎接客人的前厅，摆设的都是江湖上朋友
送的大件礼品，墙上还挂着馆主自己题写的一幅字(zi)。平时
没人的时候显得静敲敲的。南面就是武馆的大院。  
LONG);
       
	set("exits",([
               "north" : __DIR__"school2",
		"south" : __DIR__"dayuan",
	])); 
        set("valid_startroom",1);
	set("item_desc", ([
		"zi" : "上面用刚劲的大字写着“"+HBWHT HIB "有朋自远方来，不宜乐乎" NOR NOR+"。”\n" ,
	]));
	set("objects",([__DIR__"npc/zongguan":1]));// 初始化张总管
		set("no_fight",1);

	setup(); 
}
