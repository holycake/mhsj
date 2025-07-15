inherit ROOM;

void create()
{
	set("short", "内桥");
	set("long", @LONG
内桥为五代时杨吴国所建，原为南唐皇宫前御道上的正桥，称虹桥
。民间称以内桥。北宋政和年间，蔡嶷改建为石拱桥，更名蔡公桥。南
宋设建康行宫后，又改名天津桥。洪武年间复名内桥。
LONG );
	set("exits", ([
		"west"  : __DIR__"bridge_huitong",
		"north" : __DIR__"road_neiqiao",
		"south" : __DIR__"road_dazhong1",
		"east" : __DIR__"bridge_zhenghe",
	]));
	set("objects", ([
		__DIR__"npc/npc_boy" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

