inherit ROOM;

void create()
{
	set("short", "画舫二层");
	set("long", @LONG
这里是画舫二层的平台。左边放着一张书桌，桌上用镇纸压着一副未完成的
画。画中仿佛正是秦淮河沿岸的风光。
LONG );
	set("exits", ([
		"down"  : __DIR__"huafang1",
		"south"  : __DIR__"huafang6",
	]));

	set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
