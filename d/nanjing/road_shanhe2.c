inherit ROOM;



void create()

{

	set("short", "善和坊");

	set("long", @LONG

这里是京城南部的一个小街。这里面都是民居。

LONG );

	set("exits", ([

		"north" : __DIR__"road_shanhe1",

		"west" : __DIR__"room_yang_gate",

	]));

        set("outdoors", "nanjing");

	setup();

}


int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "west" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
