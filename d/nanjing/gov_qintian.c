inherit ROOM;

void create()
{
	set("short", "钦天监");
	set("long", @LONG
钦天监，掌管观察天文，并推算历法。明初沿置司天监、回回司天监，旋改称
钦天监，有监正、监副等官。本监官不得改迁他官，子孙世业，非特旨不得升调、
致仕。如有缺员，由本监逐级递补。
LONG );
	set("exits", ([
		"west" : __DIR__"road_changan4",
	]));
	setup();
	replace_program(ROOM);
}
