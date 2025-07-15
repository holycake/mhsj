//Cracked by Roath
// zoulang.c
//written by kittt

inherit ROOM; 
int valid_leave;

void create() 
{
	set("short", "走廊"); 
	set("long",@LONG
你快步穿过一条窄窄的走廊，听到南面的房间中传来阵阵
打呼声。探头一看，一家伙睡得跟死猪似的。西面是女休息室。
南面是男休息室。    
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing5",
		"west" : __DIR__"fbedroom",
		"south" : __DIR__"mbedroom",
		])); 
	
	set("no_fight",1);
	
	setup();
}

int valid_leave(object ob, string dir)
{
	if((dir=="west") && (ob->query("gender")!= "女性"))
		return notify_fail("你又不是女的跑到女休息室干什麽，想卡油啊？\n");
	if((dir=="south") && (ob->query("gender")!= "男性"))
		return notify_fail("大姑娘家要守妇道，别到处乱跑。\n");
	    	
	return ::valid_leave(ob,dir);
}