// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面
前，柜台上摆着一个牌子(paizi)， 柜台后坐着唐老板，一双精明的
上上下下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "公平交易\n
sell        卖 
buy         买
redeem      赎
value       估价
",
	]));
	set("objects", ([
		__DIR__"npc/boss_tang" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"road_laibin2",
	]));

	setup();
}
