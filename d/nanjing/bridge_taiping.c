inherit ROOM;

void create()
{
	set("short", "太平桥");
	set("long", @LONG
此桥原名笪桥，是东吴凿运渎河始建六桥中的第二座桥，时称杨烈桥。唐代时
，名为太平桥，颜真卿任南京刺史时曾在此设放生池。北宋茅山二十六代宗师笪净
重建此桥，故称笪桥。
LONG );
	set("exits", ([
		"west"  : __DIR__"bridge_chongdao",
		"north" : __DIR__"road_long2",
		"south" : __DIR__"road_sanshan2",
		"east" : __DIR__"bridge_huitong",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

