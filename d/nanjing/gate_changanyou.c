#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "长安右门");
	set("long", @LONG
长安右门位于承天门外的西侧，长安街因门而得名，取长治久安之意。门三阙
，故亦称为“三道门”，券门，汉白玉石门槛，单层歇山黄琉璃瓦顶，红墙，基础
为汉白玉石须弥座。与长安左门东西相对，为皇城通往内城西部的孔道之一。长安
右门因“东青龙，西白虎”而得名虎门。门外面是张贴皇榜――武榜之处。每年秋
审判处死刑的案件和判决皆由此门出入，好似“虎口”一般。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_waiwulong",
		"west" : __DIR__"road_changan5",
	]));
	set("objects", ([
		__DIR__"npc/bing_yulin" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<100 && dir == "east" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
