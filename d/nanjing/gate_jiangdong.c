#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "江东门");
	set("long", @LONG
江东门是南京外郭城的十八座城门之一，因城门临近长江以东而得名。江东门
东往水西门，西通上新河，有河道径流流入长江；自开国以来，一直是南京城外西
南部商业和交通中心，粮食、木材的主要集散地。外郭始建于明洪武二十三年，是
太祖为弥补和加强京城的防卫而建造，城垣本体以丘陵、垒土为主，只在城门等防
守的薄弱地段加筑城砖，城高有两三丈，城墙上则宽两丈左右。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"southeast" : __DIR__"gate_ande",
		//"north" : "/d/shaolin/yidao",
		"west"  : "/d/changan/nanyue",
              "east" : __DIR__"road_jiangdong",
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
	if ( me->query("limit") == "nanjing" && dir == "west" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
