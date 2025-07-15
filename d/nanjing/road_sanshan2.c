inherit ROOM;

void create()
{
	set("short", "三山街");
	set("long", @LONG
你走在金陵的街道上，内心极为舒坦。做为城市主干道的官街长达数里，铺
石皆方整而厚。道极宽广，虽九轨可容。左右皆缭以官廊，以蔽风雨。官廊绵延
数里，一眼望去，极其壮观。廊以木柱为支撑，上覆木板，既可遮阳又能蔽雨，
利于商家、客户交易，也方便行人。这里是城西三山门内的官街，京城的商贾多
由三山门的水西门进城，因此这条路是商贾云集之地。南边有家点心店排满了长
队，看来口碑不错。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_sanshan3",
		"south" : __DIR__"shop_gaotuan",
		"west"  : __DIR__"road_sanshan1",
		"north" : __DIR__"bridge_taiping",
	]));
	set("objects", ([
		__DIR__"npc/npc_shaonv" : 2,
		__DIR__"npc/npc_girl" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

