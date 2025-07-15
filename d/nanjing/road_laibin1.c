inherit ROOM;

void create()
{
	set("short", "来宾街市");
	set("long", @LONG
这里是长干里以经营竹木薪炭为主的街市。
LONG );
	set("exits", ([
		"south"  : __DIR__"gate_ande",
		"east" : __DIR__"road_laibin2",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
