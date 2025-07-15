#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "午门");
	set("long", @LONG
午门，通称“午朝门”，是宫城的正门，上有城楼九间，左右有两观，上有
阙楼。南边是端门和承天门。往前走就是皇宫的正殿――奉天殿。
LONG );
	set("exits", ([
		"north" : __DIR__"road_guangchang",
		"south" : __DIR__"gate_chengtian",
		"west" : __DIR__"road_gongnan1",
		"east" : __DIR__"road_gongnan2",
	]));
	set("objects", ([
		__DIR__"npc/bing_jinyi" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<2900 && dir == "east" && objectp(present("bing", environment(me))))
	        return notify_fail(HIR"锦衣卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(HIR"锦衣卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(HIR"锦衣卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	return ::valid_leave(me, dir);
}
