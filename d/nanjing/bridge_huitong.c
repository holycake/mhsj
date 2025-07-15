inherit ROOM;

void create()
{
	set("short", "会同桥");
	set("long", @LONG
这里是京城中心的一座古桥，秦淮河水穿城而过，静静流淌着。
LONG );
	set("exits", ([
		"west"  : __DIR__"bridge_taiping",
		"north" : __DIR__"road_long3",
		"south" : __DIR__"road_sanshan3",
		"east" : __DIR__"bridge_nei",
	]));
	set("objects", ([
		__DIR__"npc/npc_boy" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

