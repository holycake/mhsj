#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "高桥门");
	set("long", @LONG
高桥门为南京外郭城的十八座城门之一，因门外高桥而得名高桥门。高桥门始
建于洪武二十三年，是为弥补和加强京城的防卫而建造，城垣本体以丘陵、垒土为
主，只在城门等防守的薄弱地段加筑城砖，城高有两三丈，城墙上则宽两丈左右。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"west" : __DIR__"jiaochang_da",
		"east" : "/d/city/ximenroad",
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

	if ( me->query("limit") == "nanjing" && dir == "east" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
