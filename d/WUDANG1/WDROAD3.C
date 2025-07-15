// wdroad3.c
// netkill /98/8/17/

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，四周静悄悄的。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"wdroad2",
		"north" : __DIR__"wdroad4",
	]));

	setup();
	replace_program(ROOM);
}

