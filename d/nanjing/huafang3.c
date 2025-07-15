inherit ROOM;

void create()
{
	set("short", "画舫后厅");
	set("long", @LONG
这是画舫一层后部的船舱。主人们平常都是在这里准备和制作食材。这里虽
有厨娘，可是由于董小宛酷爱制作、发明饮食。因此常常能在这里看见她的倩影。
LONG );
	set("exits", ([
		"north"  : __DIR__"huafang2",
		"south"  : __DIR__"huafang4",
	]));
	set("objects", ([
		__DIR__"npc/mingji_dongxiaowan" : 1,
		__DIR__"npc/mingji_maxianglan" : 1,
	]));

	setup();
	replace_program(ROOM);
}
