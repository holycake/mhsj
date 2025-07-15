inherit ROOM;

void create()
{
	set("short", "内廷");
	set("long", @LONG
这里是坤宁宫，属于皇宫的内廷，宫的前边坐落着乾清宫和交泰宫。是当今皇
后娘娘居住的地方。
LONG );
	set("exits", ([
		"east" : __DIR__"gov_dong",
		"west" : __DIR__"gov_xi",
		"south" : __DIR__"gate_qianqing",
		"north" : __DIR__"gate_beian",
	]));
	set("objects", ([
		__DIR__"npc/zhouhou" : 1,
		__DIR__"npc/tianfei" : 1,
		__DIR__"npc/yuanfei" : 1,
		__DIR__"npc/gongnv" : 4,
	]));
	setup();
	replace_program(ROOM);
}
