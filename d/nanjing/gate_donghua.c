#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "东华门");
	set("long", @LONG
这里是皇城的东门――东华门。东华门和西华门的大小、形制相似，但和西华
门最大的区别是，其须弥座都为素面，没有卷叶纹的雕饰，使得东华门的风格显得
比较简朴。这一点倒真实的反映了当年太祖要求简朴建宫殿的命令。
LONG );
	set("exits", ([
		"east" : __DIR__"gate_chaoyang",
		"west" : __DIR__"gate_dongan",
		"south" : __DIR__"road_huangdong5",
		"north" : __DIR__"road_huangdong4",
	]));
	set("objects", ([
		__DIR__"npc/bing_yulin" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<1600 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "south" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
