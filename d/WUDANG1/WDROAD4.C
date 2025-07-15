// wdroad4.c
//netkill /98/8/17/
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
		//"east" : "/d/xiaoyao/shulin3",
		"south" : __DIR__"wdroad3",
		"north" : __DIR__"wdroad5",
	]));

	setup();
	replace_program(ROOM);
}

