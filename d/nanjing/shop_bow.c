inherit ROOM;

void create()
{
	set("short", "弓作坊");
	set("long", @LONG
这家店的墙壁上挂满了各种弓。还有不少下了弦的弓堆放在一边，也不知道是
做好了没有。店后面不时传来伙计们干活的声音。
LONG );
	set("exits", ([
		"east" : __DIR__"road_yujie2",
	]));
	set("objects", ([
		__DIR__"npc/boss_bow" : 1,
		__DIR__"npc/boss_bow_man" : 1,
	]));
	setup();
	replace_program(ROOM);
}

