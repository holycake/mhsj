inherit ROOM;

void create()
{
	set("short", "糕团店");
	set("long", @LONG
你走进大院，迎面是一个假山水池，池上摆着一块奇形怪状的石头，据说
是当年花石纲的遗石。水池的两旁种满了花草。东边是一棵槐树，郁郁葱葱，
遮盖了大半个院子，显得阴森恐怖。一条长廊走道通往后院，有几个家丁把守。
LONG );
	set("exits", ([
		"north" : __DIR__"road_sanshan2",
		"west" : __DIR__"road_laifeng1",
	]));
	setup();
	replace_program(ROOM);
}

