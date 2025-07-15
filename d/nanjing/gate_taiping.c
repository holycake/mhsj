#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "太平门");
	set("long", @LONG
太平门为南京十三座内城门之一，位于城东北垣，是京城的正北门，以南是
朝阳门，西北方向是神策门。因城门外为天牢所在，希望城内太平和谐，故取名
“太平门”。太平门据有山湖之险，位于钟山与玄武湖相接的位置，建在钟山向西
延伸的富贵山、覆舟山之间，是扼守钟山通向城内最近的通道。太平门东面的钟
山被称作“蟠龙”，所以这里又叫“龙脖子”。城门边专门设了一个告示榜(gaoshi)。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"north" : __DIR__"di_taiping1",
		"south" : __DIR__"road_taiping2",
	]));
	set("objects", ([
		__DIR__"npc/bing_shoucheng" : 6,
		__DIR__"npc/bing_xunluo" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n应天巡抚\n海瑞\n";
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "north" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
