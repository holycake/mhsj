inherit ROOM;

void create()
{
	set("short", "率性堂");
	set("long", @LONG
这里被用来作为抄写永乐大典的场所。
LONG );
	set("exits", ([
		"north" : __DIR__"gov_guozijian",
	]));
	set("objects", ([
		__DIR__"npc/guan_shenkeshen" : 1,
	]));
	setup();
	replace_program(ROOM);
}

