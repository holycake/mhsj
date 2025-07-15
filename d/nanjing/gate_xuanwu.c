#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "玄武门");
	set("long", @LONG
这里是皇城的正北门。门外可以达到京城外玄武湖边上的三法司。
LONG );
	set("exits", ([
		"northwest" : __DIR__"road_taiping2",
		"east" : __DIR__"road_huangbei4",
		"west" : __DIR__"road_huangbei3",
		"south" : __DIR__"gate_beian",
	]));
	set("objects", ([
		__DIR__"npc/bing_yulin" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<1600 && dir == "east" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "south" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
