inherit ROOM;

void create()
{
	set("short", "崇礼街");
	set("long", @LONG
你走在金陵的街道上，内心极为舒坦。做为城市主干道的官街长达数里，铺
石皆方整而厚。道极宽广，虽九轨可容。左右皆缭以官廊，以蔽风雨。官廊绵延
数里，一眼望去，极其壮观。廊以木柱为支撑，上覆木板，既可遮阳又能蔽雨，
利于商家、客户交易，也方便行人。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_chongli4",
		"west"  : __DIR__"road_chongli2",
		"north"  : __DIR__"lou_laibin",
	]));
	set("objects", ([
		__DIR__"npc/npc_shaonv" : 1,
		__DIR__"npc/npc_girl" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

