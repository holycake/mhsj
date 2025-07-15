#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "东安门");
	set("long", @LONG
这里是宫城的东正门。门外一直通往京城的东大门朝阳门，门外就是太祖及其
后的陵寝――孝陵了。
LONG );
	set("exits", ([
		"east" : __DIR__"gate_donghua",
		"west" : __DIR__"gov_wenyuan",
		"south" : __DIR__"road_gongdong5",
		"north" : __DIR__"road_gongdong4",
	]));
	set("objects", ([
		__DIR__"npc/bing_qishou" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<2900 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	if ( (int)me->query("feat")<2900 && dir == "south" && objectp(present("bing", environment(me))))
	        return notify_fail(HIC"旗手卫喝道：这里是宫城禁地，这位大人没什么事的话还是请回吧。\n"NOR);
	return ::valid_leave(me, dir);
}
