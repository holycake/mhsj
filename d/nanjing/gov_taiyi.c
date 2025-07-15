inherit ROOM;

void create()
{
	set("short", "太医院");
	set("long", @LONG
太医院专门负责皇室人员诊断、制药，设正五品院使一人，正六品院判二人，
正八品御医四人，从九品吏目若干人。附属有生药库和惠民药局。
LONG );
	set("exits", ([
		"east" : __DIR__"road_beixin3",
	]));
	setup();
	replace_program(ROOM);
}
