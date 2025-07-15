inherit ROOM;

void create()
{
	set("short", "织锦坊");
	set("long", @LONG
这家店专买衣服，后院是绣娘织锦、缝纫的工厂。
LONG );
	set("exits", ([
		"north" : __DIR__"road_laifeng5",
	]));
	set("objects", ([
		__DIR__"npc/boss_cloth" : 1,
	]));
	setup();
	replace_program(ROOM);
}

