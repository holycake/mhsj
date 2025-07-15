inherit ROOM;

void create()
{
	set("short", "玄真观");
	set("long", @LONG
此观系正德三年十一月由当时的太太监刘瑾所建。
LONG );
	set("exits", ([
		"northwest"  : __DIR__"gate_tongji",
		"north"  : __DIR__"gate_zhengyang",
		"south"  : __DIR__"shenji",
	]));
	/*set("objects", ([
		"/d/item/npc/zhang" : 1,
	]));*/
    set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "north" )
	        return notify_fail("\n");
	if ( me->query("limit") == "nanjing" && dir == "northwest" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
