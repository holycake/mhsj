inherit ROOM;

void create()
{
	set("short", "户部");
	set("long", @LONG
户部有尚书一人，左右侍郎各一人，下设十三清吏司（浙江、江西、湖广、陕
西、广东、山东、福建、河南、山西、四川、广西、贵州、云南），各司有郎中、
员外郎、主事等官。户部另有一些直辖机构，如宝钞提举司、印钞局、广盈库、军
储仓等。
LONG );
	set("exits", ([
		"west" : __DIR__"road_qianbu3",
	]));
	setup();
	replace_program(ROOM);
}

