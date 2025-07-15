inherit ROOM;

void create()
{
	set("short", "政和桥");
	set("long", @LONG
这里是京城中心的一座古桥。
LONG );
	set("exits", ([
		"west"  : __DIR__"bridge_nei",
		"north" : __DIR__"road_long4",
		"south" : __DIR__"road_dazhong2",
		"east" : __DIR__"matou_caobang",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

