#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "乾清门");
	set("long", @LONG
乾清门为后宫南面正大门，门外左右各有金狮一座，乾清门内为乾清宫大殿。
宫殿左边有日精门，右边有月华门，殿的东西有斜廊，廊后左边有东暖阁，右边有
西暖阁。乾清宫后面是省躬殿，制式如同华盖殿，略小一些。省躬殿后为坤宁宫，
是皇后居住的地方。坤宁宫的东、西两侧，建有柔仪殿和春和殿两座别殿。后宫之
制甚严，宫人不仅不得出宫，甚至连书信也不得传出，违者杀无赦。
LONG );
	set("exits", ([
		"north" : __DIR__"gov_nei",
		"south" : __DIR__"gov_fengtian",
		"west" : __DIR__"yuan_nei",
		"east" : __DIR__"gov_taisun",
	]));
	set("outdoors", "nanjing");
	setup();
}
