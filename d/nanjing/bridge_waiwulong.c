inherit ROOM;

void create()
{
	set("short", "外五龙桥");
	set("long", @LONG
这里是承天门外的广场，为御河上的主要桥道。它沟通着御道南北。此桥位
于承天门南，因并排五通得名五龙桥。午门内另有一五龙桥，故有内外五龙桥之
称。
LONG );
	set("exits", ([
		"east"  : __DIR__"gate_changanzuo",
		"west"  : __DIR__"gate_changanyou",
		"south" : __DIR__"road_qianbu1",
		"north" : __DIR__"gate_chengtian",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

