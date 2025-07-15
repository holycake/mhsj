#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "洪武门");
	set("long", @LONG
洪武门为皇城的正南门，原名广敬门，建成于洪武八年，洪武二十五年至二十
八年之间改名洪武门。位于正阳门内北面。洪武门后，为南北向的千步廊，两边建
有连续的廊屋，由南而北，到承天门前的横街分别转向东西而成为曲尺形。千步廊
后面两侧为“五部六府”中央官署的所在地。过了外五龙桥即是承天门。洪武门、
承天门、瑞门、午门、奉天门和奉天殿、华盖殿、谨身殿三大正殿位于同一条中轴
线上。
LONG );
	set("exits", ([
		"north" : __DIR__"road_qianbu5",
		"south" : __DIR__"road_chongli6",
		"west" : __DIR__"gov_taichang",
		"east" : __DIR__"gov_gong",
	]));
	set("objects", ([
		__DIR__"npc/bing_yulin" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (int)me->query("feat")<100 && dir == "north" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<100 && dir == "east" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	if ( (int)me->query("feat")<100 && dir == "west" && objectp(present("bing", environment(me))))
	        return notify_fail(WHT"羽林军喝道：京畿重地闲杂人等不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
