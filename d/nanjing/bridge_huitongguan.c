inherit ROOM;

void create()
{
	set("short", "会同馆桥");
	set("long", @LONG
这里是会同馆前的一座桥。会同馆和乌蛮市都在这里。
LONG );
	set("exits", ([
		"east"  : __DIR__"gov_tongzheng",
		"west"  : __DIR__"gov_huitong",
		"south" : __DIR__"bridge_wuman",
		"north" : __DIR__"bridge_baihu",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

