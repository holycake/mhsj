inherit ROOM;

void create()
{
	set("short", "成贤街");
	set("long", @LONG
这里靠近国朝最高学府，在当时世界上也是最高学府――国子监而得名，通往
国子监的道路，由于是即将准入仕途的学生使用，故此路被称为“成贤街”。
LONG );
	set("exits", ([
		"north"  : __DIR__"road_chengxian1",
		"south" : __DIR__"bridge_xinfu",
		"west" : __DIR__"jimingshan",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

