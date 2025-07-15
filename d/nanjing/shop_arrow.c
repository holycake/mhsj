inherit ROOM;

void create()
{
	set("short", "箭作坊");
	set("long", @LONG
这家店摆放着数百枝箭。有一个女孩子正在粘箭头和箭羽。店后面不时传来伙
计们干活的声音。
LONG );
	set("exits", ([
		"east" : __DIR__"road_yujie3",
	]));
	set("objects", ([
		__DIR__"npc/boss_arrow" : 1,
		__DIR__"npc/boss_arrow_girl" : 1,
	]));
	setup();
	replace_program(ROOM);
}

