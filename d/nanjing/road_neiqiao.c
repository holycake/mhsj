inherit ROOM;

void create()
{
	set("short", "内桥市");
	set("long", @LONG
这里是内桥附近的一个街市。由于地处市中心，交通便利，所以十分繁华。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_long4",
		"west"  : __DIR__"road_long3",
		"south" : __DIR__"bridge_nei",
		"north" : __DIR__"road_dashijie",
	]));
	set("objects", ([
		__DIR__"npc/npc_shaonv" : 2,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

