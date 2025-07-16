inherit ROOM;

void create()
{
	set("short", "米行");
	set("long", @LONG
你步入米行，米香与谷物的气息交织，令人心安。店内麻袋堆叠，装满白
粳米与糯米，颗粒饱满。掌柜手持算盘，吆喝着与客商议价，市井喧嚣扑面而
来。门外挑夫来往，肩扛米袋，汗水滴落，尽显金陵粮市的繁忙。
LONG );
	set("exits", ([
		"east" : __DIR__"road_hongwu2",
	]));
	setup();
	replace_program(ROOM);
}

