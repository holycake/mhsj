inherit ROOM;

void create()
{
	set("short", "武英殿");
	set("long", @LONG
武英殿始建于国朝初年，与文华殿东、西相对。武英殿位于紫禁城西路，起初
是皇帝常御之便殿，故为黄琉璃瓦顶。早期后，皇帝斋居、召见大臣都在武英殿，
后来则转到文华殿。
LONG );
	set("exits", ([
		"east" : __DIR__"gov_fengtian",
		"west" : __DIR__"road_gongxi4",
		"north" : __DIR__"yuan_nei",
		"south" : __DIR__"gov_dapao",
	]));
	set("objects", ([
		__DIR__"npc/zhuyoujian" : 1,
		__DIR__"npc/guan_yangsichang" : 1,
		__DIR__"npc/bing_dahan" : 2,
		//__DIR__"npc/gongnv" : 2,
	]));
	setup();
	replace_program(ROOM);
}
