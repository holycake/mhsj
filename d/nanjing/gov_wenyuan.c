inherit ROOM;

void create()
{
	set("short", "文渊阁");
	set("long", @LONG
内阁，为成祖首先确立。初，太祖废宰相，始有内阁，职在批答。此后权力逐
渐增大，后为国朝行政中枢。内阁辅臣人数一人至七人不等，辅臣奉使出外办事，
多自称阁部。皇帝有最终决定权力，而大学士很少有参决的机会。到仁宗、宣宗时
期，大学士均因有太子经师的恩情，而得以累加至太子三孤身份，地位日益受尊崇
。故谓后之入阁办事，无宰相之名，有宰相之实也。共有中极殿大学士、建极殿大
学士、文华殿大学士、武英殿大学士、文渊阁大学士、东阁大学士。
LONG );
	set("exits", ([
		"east" : __DIR__"gate_dongan",
		"west" : __DIR__"road_guangchang",
		"north" : __DIR__"gov_wenhua",
		"south" : __DIR__"road_gongnan2",
	]));
	setup();
	replace_program(ROOM);
}

