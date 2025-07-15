inherit ROOM;

void create()
{
	set("short", "复成桥");
	set("long", @LONG
复成桥在原开平王府邸所在――常府街东。《洪武京城志》记载此桥：“既坏
而复成之，因之名焉。”。附近有一个规模宏大的军火仓库――复成仓。复成桥的
来源还另有一种说法：复成桥原叫浮成桥。据说这桥还没有建好的时候，用木板
在上面搭了一个平的桥面，因此就叫做浮成桥。
LONG );
	set("exits", ([
		"west"  : __DIR__"road_shiyong2",
		"north" : __DIR__"road_datong1",
		"south" : __DIR__"bridge_dazhong",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

