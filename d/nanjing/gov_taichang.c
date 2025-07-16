inherit ROOM;

void create()
{
	set("short", "太常寺");
	set("long", @LONG
你置身金陵太常寺，礼乐之所，庄严肃穆。殿内檀香袅袅，案上摆放着礼
器与乐谱，隐约可见《大明会典》的抄本。朱漆柱梁雕刻精美，透出皇朝威仪
。寺官步履从容，低声议事，筹备祭祀大典。门外古柏参天，肃杀之气令人心
生敬畏。
LONG );
	set("exits", ([
		"east" : __DIR__"gate_hongwu",
	]));
	setup();
	replace_program(ROOM);
}

