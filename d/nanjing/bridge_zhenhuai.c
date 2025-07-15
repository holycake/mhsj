inherit ROOM;

void create()
{
	set("short", "镇淮桥");
	set("long", @LONG
这里是聚宝门内的一座桥，烟柳繁华的金陵城就在眼前。做为城市主干道的官
街长达数里，铺石皆方整而厚。道极宽广，虽九轨可容。左右皆缭以官廊，以蔽风
雨。官廊绵延数里，一眼望去，极其壮观。廊以木柱为支撑，上覆木板，既可遮阳
又能蔽雨，利于商家、客户交易，也方便行人。西边不断传来打银的声响，东边是
家客栈。江宁县的署衙在桥的西北。
LONG );
	set("exits", ([
		"east"  : __DIR__"kz_jixian",
		"south" : __DIR__"gate_jubao",
		"west"  : __DIR__"shop_yin",
		"north" : __DIR__"road_yujie5",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

