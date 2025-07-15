inherit ROOM;

void create()
{
	set("short", "明瓦廊");
	set("long", @LONG
羊角灯者，旧为金陵特产。用羊角煎熬成液，和以彩色，凝而压薄成片，谓之
明瓦。此地皆制此者也。连缀明瓦而成灯，透光明，无火患，且不脆裂，故宫中亦
用之。
LONG );
	set("exits", ([
		"north"  : __DIR__"road_chouduan",
		"south" : __DIR__"road_dashijie",
		"west" : __DIR__"shop_lejia",
		"east" : __DIR__"road_zhongzheng1",
	]));
	set("objects", ([
		__DIR__"npc/npc_shaonv" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
