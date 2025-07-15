#include <room.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "安德门");
	set("long", @LONG
安德门为南京外郭城的十八座城门之一，处于明外郭小安德门与凤台门之间，
后来为了区别于小安德门，又将其称大安德门。安德门以及外郭始建于洪武二十三
年，是太祖为弥补和加强京城的防卫而建造，城垣本体以丘陵、垒土为主，只在城
门等防守的薄弱地段加筑城砖，城高有两三丈，城墙上则宽两丈左右。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"north" : __DIR__"road_laibin1",
		"northwest" : __DIR__"gate_jiangdong",
		"west" : "/d/changan/broadway3",
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
	if ( me->query("limit") == "nanjing" && dir == "west" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
