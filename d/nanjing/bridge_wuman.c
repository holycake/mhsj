inherit ROOM;

void create()
{
	set("short", "乌蛮桥");
	set("long", @LONG
桥边为专为外邦贡使和商人居住贸易的处所――乌蛮驿又称乌蛮市。
LONG );
	set("exits", ([
		"north" : __DIR__"bridge_huitongguan",
		"south" : __DIR__"road_changan2",
		"east" : __DIR__"bingma_jinyi",
		"west" : __DIR__"gov_wuman",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

