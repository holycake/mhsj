#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "正阳门");
	set("long", @LONG
正阳门是南京城墙十三座内城门之一，是京城的正门，内外均有瓮城的复合
型瓮城。每逢孝陵大祀牲牢、国学二丁祭品，户部粮长勘合，俱由正阳正门入。
城门边专门设了一个告示榜(gaoshi)。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"north" : __DIR__"road_chongli6",
		"south" : __DIR__"si_xuanzhen",
	]));
	set("objects", ([
		__DIR__"npc/bing_shoucheng" : 6,
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

	if ( me->query("limit") == "nanjing" && dir == "south" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
