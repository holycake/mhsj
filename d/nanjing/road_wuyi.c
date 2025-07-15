inherit ROOM;

void create()
{
	set("short", "乌衣巷");
	set("long", @LONG
乌衣巷在文德桥南，三国东吴时禁军驻地。由于当时禁军身着黑色军服，故此
地俗语称乌衣巷。东晋时以王导、谢安两大家族，都居住在乌衣巷，人称其子弟为
“乌衣郎”。
LONG );
	set("exits", ([
		"north" : __DIR__"river_qinhuai4",
		"south" : __DIR__"road_shanhe1",
		"west" : __DIR__"bridge_wende",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

