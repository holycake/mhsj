inherit ROOM;

void create()
{
	set("short", "漕帮码头");
	set("long", @LONG
这里是押解漕船上京的码头，全国各地的漕船都在此汇聚。时间久了，漕船上
押运的小武官和水手以及一些底层的读书人结为了漕帮。
LONG );
	set("exits", ([
		"west"  : __DIR__"bridge_zhenghe",
		"east" : __DIR__"shop_liji",
		"north" : __DIR__"road_long5",
		"south" : __DIR__"road_dazhong3",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
