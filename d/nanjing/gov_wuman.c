inherit ROOM;

void create()
{
	set("short", "乌蛮驿");
	set("long", @LONG
按国朝朝贡制度，贡使可携带特产，由礼部规定时间，在驿馆开市交易。所以
乌蛮驿又称乌蛮市。这里是专为外邦贡使和商人居住贸易设立的馆舍，又称乌
蛮市。真正的衙署不在这个地方。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_wuman",
	]));
	setup();
	replace_program(ROOM);
}

