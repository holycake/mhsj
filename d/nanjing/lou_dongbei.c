inherit ROOM;

void create()
{
	set("short", "东北角楼");
	set("long", @LONG
宫城西路有兴庆宫，内藏衣物、扇子千余箱。又有大善殿，在小城之上，城
下为宫城内河石梁。大善殿设六门，为明太祖览读之所，殿后有石假山，下假山
为望江楼，楼后为九五飞龙殿，面阔九间，殿基座有天宫壁，内藏佛龛。
LONG );
	set("exits", ([
		"south"  : __DIR__"road_huangdong1",
		"west"  : __DIR__"road_huangbei5",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

