inherit ROOM;

void create()
{
	set("short", "轻烟楼");
	set("long", @LONG
太祖于金陵建十六楼，以处官伎：曰来宾，曰重译，曰清江，曰石城，曰鹤
鸣，曰醉仙，曰乐民，曰集贤，曰讴歌，曰鼓腹，曰轻烟，曰淡粉，曰梅妍，曰
柳翠，曰南市，曰北市，盖当时缙绅通得用官伎。其中来宾、重译二楼是专门招
待外国使节的。只见此楼高基重檐、宽敞华丽，有著名书法家题写名匾，文人学
士题咏律诗，以壮观瞻。端的是“宝炬通宵彻，鸾笙协气和，臣民涵圣泽，齐唱太
平歌。”
LONG );
	set("exits", ([
		"east"  : __DIR__"river_qinhuai2",
		"north" : __DIR__"road_dazhong3",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

