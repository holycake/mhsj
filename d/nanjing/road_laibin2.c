inherit ROOM;

void create()
{
	set("short", "来宾街市");
	set("long", @LONG
这里是长干里以经营竹木薪炭为主的街市。
LONG );
	set("exits", ([
		"west"  : __DIR__"road_laibin1",
		"east" : __DIR__"road_changganli1",
		"south" : __DIR__"shop_dangpu",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
