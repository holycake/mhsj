#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西华门");
	set("long", @LONG
西华门是紫禁城西门，始建于永乐十八年。西华门西向，与东华门遥相对应，
门外设有下马碑石。西华门与东华门形制基本相同，平面矩形，红色城台，汉白玉
须弥座，城台当中辟三座券门，券洞外方内圆，门钉为纵九横九。城台上建有城楼
，黄琉璃瓦重檐庑殿顶，基座围以汉白玉栏杆。城楼面阔五间，进深三间，四周出
廊，梁枋绘墨线大点金旋子彩画。门楼用于安放阅兵所用棉甲及锭钉盔甲。
LONG );
	set("exits", ([
		"east" : __DIR__"gov_zhujian1",
		"west" : __DIR__"bridge_xuanjin",
		"south" : __DIR__"road_huangxi5",
		"north" : __DIR__"road_huangxi4",
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
	if ( (int)me->query("feat")<1600 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<1600 && dir == "south" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
