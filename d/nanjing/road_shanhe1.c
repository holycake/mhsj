inherit ROOM;

void create()
{
	set("short", "善和坊");
	set("long", @LONG
这里是京城南部的一个小街。这里面都是民居。
LONG );
	set("exits", ([
		"south" : __DIR__"road_shanhe2",
		"north" : __DIR__"road_wuyi",
		"northwest" : __DIR__"bridge_wende",
	]));
	set("objects", ([
		__DIR__"npc/npc_boy" : 2,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

