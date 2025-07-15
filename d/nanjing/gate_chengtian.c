#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "承天门");
	set("long", @LONG
承天门上建门楼五间。门南广场上有条御河，上有外五龙桥。沿着南北向御
道往北走是端门，规制同承天门，上建门楼五间。
LONG );
	set("exits", ([
		"east" : __DIR__"gov_taimiao",
		"west" : __DIR__"gov_sheji",
		"south" : __DIR__"bridge_waiwulong",
		"north" : __DIR__"gate_wu",
	]));
	set("objects", ([
		__DIR__"npc/bing_jinyi" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<1600 && dir == "east" && objectp(present("bing", environment(me))))
	        return notify_fail(HIR"锦衣卫喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(HIR"锦衣卫喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(HIR"锦衣卫喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
