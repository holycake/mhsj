#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "长安左门");
	set("long", @LONG
长安左门位于承天门外的东侧，长安街因门而得名，取长治久安之意。门三阙
，故亦称为“三道门”，券门，汉白玉石门槛，单层歇山黄琉璃瓦顶，红墙，基础
为汉白玉石须弥座。与长安右门东西相对，为皇城通往内城东部的孔道之一。长安
左门因“东青龙，西白虎”而得名龙门。门外面是张贴皇榜――文榜之处。每科应
试的举子皆汇聚于此，故人们常称“登龙门”。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_qinglong",
		"west" : __DIR__"bridge_waiwulong",
	]));
	set("objects", ([
		__DIR__"npc/bing_yulin" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<100 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
