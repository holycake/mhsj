// xiaolu2.c 林间小径
// netkill /98/8/14/

inherit ROOM;

void create()
{
	set("short", "林间小径");
	set("long", @LONG
	你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶
声和鸟鸣声，听不到别的动静。向北则是后山了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"houmen",
		"south" : __DIR__"xiaolu1",
	]));
	
	setup();
	replace_program(ROOM);
}

