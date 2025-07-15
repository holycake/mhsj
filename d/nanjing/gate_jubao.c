#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "聚宝门");
	set("long", @LONG
聚宝门是京城正南门，规模仅次于通济门的城门，有“天下第一瓮城”之称。
聚宝门的历史可追溯到南唐都城江宁府和南宋陪都建康府城南门，明洪武二至
八年扩建而成。聚宝门前后有内外秦淮河径流横贯东西，南边交通连接长干桥
，北边连接镇淮桥，是城南交通咽喉所在，聚宝门东西两侧为老门东与老门西
自古便是江南繁华之地。聚宝门城堡布局严整、构造独特，由三个瓮城组成，
呈“目”字形结构，每道瓮城都有一门一闸。门是双扉包铁门，内设有栓槽，用
来供木栓紧闭大门所用。整个城共有二十七个藏兵洞，可以藏兵三千余人，城
门边专门设了一个告示榜(gaoshi)。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"bridge_jubao",
		"north" : __DIR__"bridge_zhenhuai",
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
