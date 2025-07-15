inherit ROOM;

void create()
{
	set("short", "礼部");
	set("long", @LONG
礼部有尚书一人，左右侍郎各一人，下设四个清吏司（仪制、祀祭、主客、精
膳），各司有郎中、员外郎、主事等官。另辖铸印局等。
LONG );
	set("exits", ([
		"west" : __DIR__"road_qianbu4",
	]));
	setup();
	replace_program(ROOM);
}

