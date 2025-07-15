inherit ROOM;

void create()
{
	set("short", "大中街市");
	set("long", @LONG
你走在金陵的街道上，内心极为舒坦。做为城市主干道的官街长达数里，铺
石皆方整而厚。道极宽广，虽九轨可容。左右皆缭以官廊，以蔽风雨。官廊绵延
数里，一眼望去，极其壮观。廊以木柱为支撑，上覆木板，既可遮阳又能蔽雨，
利于商家、客户交易，也方便行人。这里是城西三山门内的官街，京城的商贾多
由三山门的水西门进城，因此这条路是商贾云集之地。北边是漕运码头， 有不少
工人在搬运货物。南边管弦之声不断，却是当年太祖设立的十六官妓楼之一――
轻烟楼。
LONG );
	set("exits", ([
		"east"  : __DIR__"bridge_huaiqing",
		"south" : __DIR__"lou_qingyan",
		"west"  : __DIR__"road_dazhong2",
		"north" : __DIR__"matou_caobang",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

