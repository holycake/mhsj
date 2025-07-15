inherit ROOM;

void create()
{
	set("short", "神机营");
	set("long", @LONG
京城禁卫军三大营之一，是国朝军队中最先列装火器的特殊部队。中央的训练
场上有几队士兵在进行射击训练。
LONG );
	set("exits", ([
		"east"  : __DIR__"jiaochang_da",
		"west"  : __DIR__"road_dashi",
		"north"  : __DIR__"si_xuanzhen",
	]));
	set("objects", ([
		__DIR__"npc/bing_huochong" : 6,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

