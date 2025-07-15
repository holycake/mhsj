inherit ROOM;

void create()
{
	set("short", "靴鞋老店");
	set("long", @LONG
这是家专门制作鞋靴的百年老店，保持着前店后厂的特色。据说自洪武年初，
这家店老板的祖上就已经开始营业了。至今生意兴隆。
LONG );
	set("exits", ([
		"north" : __DIR__"road_dazhong2",
		"west" : __DIR__"road_yujie1",
	]));
	set("objects", ([
		__DIR__"npc/boss_xue" : 1,
	]));
	setup();
	replace_program(ROOM);
}

