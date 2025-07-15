#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北安门");
	set("long", @LONG
这里是宫城的北正门。附近有兴庆宫，内藏衣物、扇子千余箱。又有大善殿
，在小城之上，城下为宫城内河石梁。大善殿设六门，为明太祖览读之所，殿后
有石假山，下假山为望江楼，高际霄汉，已不可梯。楼后为九五飞龙殿，间凡九
除，多萱草，殿基座有天宫壁，内藏佛龛。
LONG );
	set("exits", ([
		"north" : __DIR__"gate_xuanwu",
		"south" : __DIR__"gov_nei",
		"west" : __DIR__"road_gongbei1",
		"east" : __DIR__"road_gongbei2",
	]));
	set("objects", ([
		__DIR__"npc/bing_qishou" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<2900 && dir == "east" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "south" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	return ::valid_leave(me, dir);
}
