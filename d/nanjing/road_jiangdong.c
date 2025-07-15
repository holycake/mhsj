inherit ROOM;

void create()
{
	set("short", "江东路");
	set("long", @LONG
这里是京城西门三山门外的一条路。北边为莫愁湖，南有南湖。往西走，就是
外郭城的江东门了。
LONG );
	set("exits", ([
		"east"  : __DIR__"gate_sanshan",
		"south" : __DIR__"lake_south",
		"west"  : __DIR__"gate_jiangdong",
		"north" : __DIR__"lake_mochou",
	]));
        set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "east" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
