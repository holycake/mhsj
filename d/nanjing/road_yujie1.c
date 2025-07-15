inherit ROOM;

void create()
{
	set("short", "古御街");
	set("long", @LONG
你走在金陵的街道上，内心极为舒坦。做为城市主干道的官街长达数里，铺
石皆方整而厚。道极宽广，虽九轨可容。左右皆缭以官廊，以蔽风雨。官廊绵延
数里，一眼望去，极其壮观。廊以木柱为支撑，上覆木板，既可遮阳又能蔽雨，
利于商家、客户交易，也方便行人。这里是南唐时候皇宫的御街，如今却成为百
姓出行的道路，令人不由感叹沧海桑田。西边有家香铺，卖各种香药和化妆品。
东边有家鞋店，各色鞋靴琳琅满目。
LONG );
	set("exits", ([
		"east"  : __DIR__"shop_xuexie",
		"south" : __DIR__"road_yujie2",
		"west"  : __DIR__"shop_xiang",
		"north" : __DIR__"road_dazhong1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

