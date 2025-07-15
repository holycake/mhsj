inherit ROOM;

void create()
{
	set("short", "乐家老铺");
	set("long", @LONG
这是家百年老字号，在当地行医已有数代。店面很大南边的一间房是医生看诊
的地方。北边是专门出手药材的地方。
LONG );
	set("exits", ([
		"north" : __DIR__"shop_yaopu",
		"west" : __DIR__"road_hongwu3",
		"east" : __DIR__"road_mingwa",
	]));
    set("objects", ([
                __DIR__"npc/boss_yaowen" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

