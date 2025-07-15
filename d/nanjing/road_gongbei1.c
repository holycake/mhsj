inherit ROOM;

void create()
{
	set("short", "宫城北");
	set("long", @LONG
这里是宫城的最北面。附近有兴庆宫，内藏衣物、扇子千余箱。又有大善殿
，在小城之上，城下为宫城内河石梁。大善殿设六门，为明太祖览读之所，殿后
有石假山，下假山为望江楼，高际霄汉，已不可梯。楼后为九五飞龙殿，间凡九
除，多萱草，殿基座有天宫壁，内藏佛龛。
LONG );
	set("exits", ([
		"south"  : __DIR__"gov_xi",
		"east"  : __DIR__"gate_beian",
		"west"  : __DIR__"road_gongxi1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

