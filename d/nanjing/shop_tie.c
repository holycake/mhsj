inherit ROOM;

void create()
{
	set("short", "铁作坊");
	set("long", @LONG
这家店外有个两楼多高的大炉子。门口的摊子摆满了各式各样的武器、装备和
各种工具、农具。
LONG );
	set("exits", ([
		"east" : __DIR__"road_yujie4",
		"west" : __DIR__"bridge_xin",
	]));
	set("objects", ([
		__DIR__"npc/boss_tie" : 1,
	]));
	setup();
	replace_program(ROOM);
}

