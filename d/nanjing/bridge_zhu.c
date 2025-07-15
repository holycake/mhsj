inherit ROOM;

void create()
{
	set("short", "竹桥");
	set("long", @LONG
这里是京城北部，青溪上的一座桥。正北有一个小校场，往东北经太平门就是
外城了。
LONG );
	set("exits", ([
		"west"  : __DIR__"shop_maji",
		"north" : __DIR__"road_taiping1",
		"south" : __DIR__"road_datong1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

