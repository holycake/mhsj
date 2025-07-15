inherit ROOM;

void create()
{
	set("short", "太庙");
	set("long", @LONG
这里是承天门内之东，庙前有石桥，门左右皆樊松竹杂灌，门内唐左右位咸
有井，井覆以亭。入左角门，过石梁，明庭上须弥座，座凡三重，皆可路。庙间
九，丹陛三重，檐际皆有网丝，中设灵座，皆设灵衣。由右入观寝室，室各有灵
床，床左右悬悬灯，床前素壁，壁前各设方木椅，椅上籍黄褥，褥上各设裳衣，
椅麓设履。
LONG );
	set("exits", ([
		"east" : __DIR__"road_huangnan3",
		"west" : __DIR__"gate_chengtian",
	]));
	setup();
	replace_program(ROOM);
}

