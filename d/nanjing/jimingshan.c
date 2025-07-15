inherit ROOM;

void create()
{
	set("short", "鸡鸣山");
	set("long", @LONG
鸡笼山又名北极阁，东连九华山，西接鼓楼岗，北近玄武湖，为钟山延伸入城
余脉。春秋战国时期，以其山势浑圆汕，形似鸡笼而得名。鸡笼山高约30余丈，是
城中重要制高点。南朝齐武帝到钟山射雉至此闻鸡鸣，故鸡笼山又改称鸡鸣山。明
初设观象台于山上，又名钦天山。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_chengxian2",
		"south" : __DIR__"road_chouduan",
		"north" : __DIR__"si_jiming",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

