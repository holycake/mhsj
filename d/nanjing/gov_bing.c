inherit ROOM;

void create()
{
	set("short", "兵部");
	set("long", @LONG
兵部有尚书一人，左右侍郎各一人，下设四个清吏司（武选、职方、车驾、武
库），各司有郎中、员外郎、主事等官。另辖会文馆等机构。
LONG );
	set("exits", ([
		"west" : __DIR__"road_qianbu5",
	]));
	setup();
	replace_program(ROOM);
}

