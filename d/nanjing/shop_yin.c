inherit ROOM;

void create()
{
	set("short", "银作坊");
	set("long", @LONG
你走进银作坊，炉火熊熊，银光闪烁。匠人手持錾刀，细琢银锭与饰物，
叮当声清脆悦耳。案上摆放着精致的银簪与镯子，雕花繁复，尽显明代工艺之
美。坊外商贾低语，交易银两，坊内热气蒸腾，透出金陵富庶之气。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_zhenhuai",
	]));
	setup();
	replace_program(ROOM);
}

