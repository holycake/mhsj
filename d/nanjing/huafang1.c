inherit ROOM;

void create()
{
	set("short", "画舫前厅");
	set("long", @LONG
这是画舫一层靠近船首的船舱。被布置成会客厅的样子。华美别致的紫檀木
家具配上古朴雅致的装饰，给人舒适的感觉。边上有楼梯可以上楼。
LONG );
	set("exits", ([
		"out"  : __DIR__"huafang",
		"south"  : __DIR__"huafang2",
		"up"  : __DIR__"huafang5",
	]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

	setup();
	replace_program(ROOM);
}
