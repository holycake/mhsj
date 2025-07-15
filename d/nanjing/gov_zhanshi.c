inherit ROOM;

void create()
{
	set("short", "詹事府");
	set("long", @LONG
詹事府是负责辅助太子的机构设正三品詹事一人，正四品少詹事一人，正六品
府丞一人。詹事府设左右春坊、司经局、主簿厅。
LONG );
	set("exits", ([
		"east" : __DIR__"road_beixin2",
	]));
	setup();
	replace_program(ROOM);
}

