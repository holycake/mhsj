#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西安门");
	set("long", @LONG
这里是宫城的西正门。门外分别是内宫的诸监和内库。往东就是宫城了。
LONG );
	set("exits", ([
		"east" : __DIR__"gov_dapao",
		"west" : __DIR__"gov_zhujian1",
		"south" : __DIR__"road_gongxi5",
		"north" : __DIR__"road_gongxi4",
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
	if ( (int)me->query("feat")<2900 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "south" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	return ::valid_leave(me, dir);
}
