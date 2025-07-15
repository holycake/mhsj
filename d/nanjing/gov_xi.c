inherit ROOM;

void create()
{
	set("short", "西宫");
	set("long", @LONG
西宫旁为内花园，为当年太祖燕居之所。西宫前殿面阔五间，设宝座龙床，
后殿亦面阔五间，中为沉香木宝座，两旁内间有龙床，各含小床，可以周回。西
宫左右厢房十四间，宫后为御用厨，炉灶以铜砖砌成。西宫左右又有十二院，每
院宫殿三间，左右厢房八间，厨房三间。出西宫为鬃殿，鸱吻檐脊皆鬃所成，四
周为格，凡四十壁。南为武英殿，旁为大庖。
LONG );
	set("exits", ([
		"east" : __DIR__"gov_nei",
		"west" : __DIR__"road_gongxi2",
		"south" : __DIR__"yuan_nei",
		"north" : __DIR__"road_gongbei1",
	]));
	set("objects", ([
		__DIR__"npc/gongnv" : 4,
	]));
	setup();
	replace_program(ROOM);
}

