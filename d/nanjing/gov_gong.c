inherit ROOM;

void create()
{
	set("short", "工部");
	set("long", @LONG
工部有尚书一人，左右侍郎各一人，下设四个清吏司（营缮、虞衡、都水、屯
田），各司有郎中、员外郎、主事等官。另辖宝源局、军器局等机构。
LONG );
	set("exits", ([
		"west" : __DIR__"gate_hongwu",
	]));
	setup();
	replace_program(ROOM);
}

