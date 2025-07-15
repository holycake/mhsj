#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "石城门");
	set("long", @LONG
石城门为十三座内城门之一，坐东面西，为南京城城防的锁钥，兵家必争之
地。石城门历史最早可追溯到南唐都城的大西门，后改建后为福船型（鱼腹型）
内瓮城城门，由两道瓮城、三通城门组成，皆为拱券砌筑，城门上建有城楼。南
京民间习惯称之为旱西门。这里，地近楚金陵邑城、六朝石头城。史载：公元前
333年，楚威王熊商灭越之后，视这里山川形势不凡，有“王者都邑之气”，传说
他铸造一对金人分别埋藏于钟山和幕府山下，以镇“山川灵异”。楚威王还看中临
江陡峭的石头山，于是，在山上修筑城寨，取名金陵邑。城门边专门设了一个告
示榜(gaoshi)。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"lake_mochou",
		"east" : __DIR__"road_long1",
	]));
	set("objects", ([
		__DIR__"npc/bing_shoucheng" : 6,
		__DIR__"npc/bing_xunluo" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n应天巡抚\n海瑞\n";
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "south" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
