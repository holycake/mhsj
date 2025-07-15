// xilang.c 西厢走廊
// by Xiang

inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
	你走在一条走廊上，四面静悄悄的，没一点声音。
LONG
	);

	set("exits", ([
		"west" : __DIR__"xilang",
		"east" : __DIR__"sanqingdian",
	]));
	setup();
	replace_program(ROOM);
}

