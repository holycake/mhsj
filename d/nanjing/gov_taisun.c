inherit ROOM;

void create()
{
	set("short", "太孙宫");
	set("long", @LONG
这里是皇太孙宫。由于当今尚未有皇太孙。所以这里一直空着，只看到几个宫
女在打扫宫院。这是一座三梁的宫殿，宫前种植了很多梅树。宫里五彩雕镂的宝座
、龙床，床俱全。
LONG );
	set("exits", ([
		"east" : __DIR__"road_gongdong3",
		"west" : __DIR__"gate_qianqing",
		"south" : __DIR__"gov_wenhua",
		"north" : __DIR__"gov_dong",
	]));
	setup();
	replace_program(ROOM);
}

