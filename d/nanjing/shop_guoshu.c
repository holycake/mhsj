inherit ROOM;

void create()
{
	set("short", "果蔬店");
	set("long", @LONG
这里是城东皇宫区的一个果蔬店，摊子上还摆了几个牌子，写着“孝陵特产”
几个字。这里除了孝陵卫的两大特产剪绒和陵园瓜外，还有好几十坛子酒。店外
的招牌上写着“孝陵卫上满街香，几处行人在醉乡。一饮迎风真欲倒，洋河未必逊
高粮。”
LONG );
	set("exits", ([
		"east" : __DIR__"road_beixin5",
	]));
	set("objects", ([
		__DIR__"npc/boss_fruit" : 1,
	]));
	setup();
}
