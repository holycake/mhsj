inherit ROOM;

void create()
{
	set("short", "珠宝廊");
	set("long", @LONG
你走在金陵的街道上，内心极为舒坦。做为城市主干道的官街长达数里，铺
石皆方整而厚。道极宽广，虽九轨可容。左右皆缭以官廊，以蔽风雨。官廊绵延
数里，一眼望去，极其壮观。廊以木柱为支撑，上覆木板，既可遮阳又能蔽雨，
利于商家、客户交易，也方便行人。这里是城西三山门和城东通济门之间的官街
交汇的地段。这里商贾云集，店铺多售珠宝，是京城商业及居民区的中心地带。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_dazhong2",
		"south" : __DIR__"road_yujie1",
		"west"  : __DIR__"road_sanshan3",
		"north" : __DIR__"bridge_nei",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

