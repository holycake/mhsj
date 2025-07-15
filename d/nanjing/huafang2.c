inherit ROOM;

void create()
{
	set("short", "画舫主厅");
	set("long", @LONG
这是画舫一层中部的船舱。是画舫主人主要的活动场所。也是用膳的地方。
中间的大桌上放着几碟精致的点心。两边摆放着海南花梨木制成的家具。有两个
姑娘在下棋，还有一个姑娘在观战，气氛好不热烈。边上站着几个丫鬟在说着
悄悄话。
LONG );
	set("exits", ([
		"north"  : __DIR__"huafang1",
		"south"  : __DIR__"huafang3",
	]));
	set("objects", ([
		__DIR__"npc/mingji_liurushi" : 1,
		__DIR__"npc/mingji_koubaimen" : 1,
		__DIR__"npc/mingji_gumeisheng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
