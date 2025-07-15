#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "广庭");
	set("long", @LONG
这里是午门与正殿奉天殿的前门奉天门之间的广场。东为文楼，西为武楼。
是朝廷重臣平时上朝的所在。这里有条护城河，上为内五龙桥，河水是以当年填
塞以修建皇宫的燕雀湖余水为水源，护城河水最后汇入秦淮河。
LONG );
	set("exits", ([
		"north" : __DIR__"gov_fengtian",
		"south" : __DIR__"gate_wu",
		"west" : __DIR__"gov_dapao",
		"east" : __DIR__"gov_wenyuan",
	]));
	set("objects", ([
		__DIR__"npc/bing_dahan" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}
