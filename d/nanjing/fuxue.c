inherit ROOM;

void create()
{
	set("short", "府学");
	set("long", @LONG
这里是应天府的地方官学的学宫所在。往北是祭祀孔子的孔庙。
LONG );
	set("exits", ([
		"north" : __DIR__"fuzimiao",
		"west" : __DIR__"road_yujie4",
		"south" : __DIR__"bridge_wuding",
		"east" : __DIR__"bridge_wende",
	]));
	setup();
	replace_program(ROOM);
}

