inherit ROOM;

void create()
{
	set("short", "东宫");
	set("long", @LONG
这里是当今太子视事之所――东宫。只看到几个宫女在打扫宫院。这是一座三
梁的宫殿，宫前种植了很多梅树。宫里五彩雕镂的宝座、龙床，床俱全。
LONG );
	set("exits", ([
		"east" : __DIR__"road_gongdong2",
		"west" : __DIR__"gov_nei",
		"south" : __DIR__"gov_taisun",
		"north" : __DIR__"road_gongbei2",
	]));
	set("objects", ([
		__DIR__"npc/zhucilang" : 1,
		__DIR__"npc/gongnv" : 4,
	]));
	setup();
	replace_program(ROOM);
}

