
inherit ROOM;

void create()
{
	set("short", "古墓石林");
	set("long", @LONG
这是一片看似杂乱无章的石头阵，一走进来，你仿佛迷失了方向。
LONG
	);

	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"sl0",
		"north" : __DIR__"sl3",
	]));
	setup();
	replace_program(ROOM);
}
