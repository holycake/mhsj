inherit ROOM;

void create()
{
	set("short", "南湖");
	set("long", @LONG
这里是莫愁湖南边的一个湖。和莫愁湖并称为姐妹湖。
LONG );
	set("exits", ([
		"north" : __DIR__"road_jiangdong",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

