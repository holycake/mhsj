inherit ROOM;

void create()
{
	set("short", "鞍辔坊");
	set("long", @LONG
你走进鞍辔坊，皮革与木料的气息扑鼻而来。坊内匠人挥汗如雨，敲打着
马鞍与辔头，叮当声不绝于耳。墙边堆放着雕花马鞍，皮带上嵌着铜饰，尽显
工匠巧思。几匹骏马在院中试鞍，嘶鸣声回荡，透出金陵商贸的勃勃生机。
LONG );
	set("exits", ([
		"west" : __DIR__"road_laifeng3",
	]));
	setup();
	replace_program(ROOM);
}

