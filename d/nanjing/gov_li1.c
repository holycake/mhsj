inherit ROOM;

void create()
{
	set("short", "吏部");
	set("long", @LONG
吏部有尚书（正二品）一人，左右侍郎（正三品）各一人，下设四个清吏司（
文选、验封、稽勋、考功），每司各有郎中（正五品）一人，员外郎（从五品）一
人，主事（正六品）一人等官。吏部职权特重，为六部之首。
LONG );
	set("exits", ([
		"west" : __DIR__"road_qianbu2",
	]));
	set("objects", ([
		__DIR__"npc/guan_chenyun" : 1
	]));
	setup();
	replace_program(ROOM);
}

