inherit ROOM;

void create()
{
	set("short", "大庖厨");
	set("long", @LONG
这里是国家进行祭祀时准备祭品的地方。庖之祭器皆木色，咸朱，凡祭列于红
几，几上咸刊定荐物品，位祭则携几以往。
LONG );
	set("exits", ([
		"east" : __DIR__"road_guangchang",
		"west" : __DIR__"gate_xian",
		"north" : __DIR__"gov_wuying",
		"south" : __DIR__"road_gongnan1",
	]));
	setup();
	replace_program(ROOM);
}

