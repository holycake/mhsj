inherit ROOM;

void create()
{
	set("short", "船尾");
	set("long", @LONG
这里是画舫的船尾。有人在中间的琴桌上弹奏着一床古琴。几个姑娘或执扇
凭栏，或低头品着琴音，好不悠闲自在。
LONG );
	set("exits", ([
		"north"  : __DIR__"huafang3",
	]));
	set("objects", ([
		__DIR__"npc/mingji_chenyuanyuan" : 1,
		__DIR__"npc/mingji_biansaisai" : 1,
		__DIR__"npc/mingji_lixiangjun" : 1,
	]));

	setup();
	replace_program(ROOM);
}
