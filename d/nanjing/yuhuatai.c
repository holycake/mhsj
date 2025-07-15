inherit ROOM;

void create()
{
	set("short", "雨花台");
	set("long", @LONG
雨花台下一派沙土中常有五色石子，状如韦曷，青、碧、红、绿不等，亦有
极通明可爱者，不减宝石也。雨后，行人往往拾得之。岂当时天所雨花，其精气
凝而为石耶？
LONG );
	set("exits", ([
		"east"  : __DIR__"si_baoen",
		"south" : __DIR__"jubaoshan",
		"west"  : __DIR__"bingma_nan",
		"north" : __DIR__"bridge_jubao",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

