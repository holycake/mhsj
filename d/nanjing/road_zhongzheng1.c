inherit ROOM;

void create()
{
	set("short", "中正街");
	set("long", @LONG
中正街南唐時为皇宮正門外橫街的東段，国朝开辟为东西向的官街，名为中正
街。北面有万寿宫、火神庙、八腊庙、上江考棚。
LONG );
	set("exits", ([
		"south" : __DIR__"road_zhongzheng2",
		"east" : __DIR__"road_shiyong1",
		"west" : __DIR__"road_mingwa",
		"north" : __DIR__"bridge_xinfu",
	]));
	set("objects", ([
		__DIR__"npc/npc_shaonv" : 1,
		__DIR__"npc/npc_girl" : 1,
		__DIR__"npc/npc_boy" : 2,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

