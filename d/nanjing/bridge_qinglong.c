inherit ROOM;

void create()
{
	set("short", "青龙桥");
	set("long", @LONG
这里是皇城外的一座桥，“按照堪舆术所谓的“左青龙，右白虎”之制命名。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_changan6",
		"west"  : __DIR__"gate_changanzuo",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

