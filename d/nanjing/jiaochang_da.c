inherit ROOM;

void create()
{
	set("short", "大校场");
	set("long", @LONG
这里是军营操练士卒的地方。场地里有不少军队正在进行体能的操练。
LONG );
	set("exits", ([
		"east"  : __DIR__"gate_gaoqiao",
		"west"  : __DIR__"shenji",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

