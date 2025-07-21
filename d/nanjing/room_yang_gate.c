inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
这里是路尽头的一个民居。门面虽然不大，倒也古朴整洁。
LONG );
	set("exits", ([
		"east" : __DIR__"road_shanhe2",
		"west" : __DIR__"room_zhangfang",
		"north" : __DIR__"room_ting",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "east" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
