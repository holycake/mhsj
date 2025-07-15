#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "三山门");
	set("long", @LONG
三山门位于南京城西南，坐东向西，为水陆两栖城门，是南京内城十三城门
之一，面临秦淮河，是从水路进出南京城的主要通道，故而俗称水西门。三山门
历史可追溯到南唐都城以及宋、元金陵城的龙光门，洪武十九年重新建造，因南
眺三山故才改名为三山门。三山门为福船型（鱼腹型）内瓮城的主城门。规模仅
次于聚宝门，与通济门略同，建有内瓮城三座，门垣共四道，每两道城墙间设瓮
城，内瓮城呈船形或者鱼腹型，供作储兵防守之用。城门边专门设了一个告示榜
(gaoshi)。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"west" : __DIR__"road_jiangdong",
		"east" : __DIR__"road_sanshan1",
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
