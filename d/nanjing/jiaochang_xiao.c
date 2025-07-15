inherit ROOM;

void create()
{
	set("short", "小校场");
	set("long", @LONG
这里是靠近京城太平门内的一处校场。有不少军人正在操练。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_taiping2",
		"south"  : __DIR__"road_taiping1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

