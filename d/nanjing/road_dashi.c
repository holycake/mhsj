inherit ROOM;

void create()
{
	set("short", "大市");
	set("long", @LONG
这里是长干里以经营粮食和其他农副产品为主的大市
LONG );
	set("exits", ([
		"east"  : __DIR__"shenji",
		"west" : __DIR__"road_changganli2",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
