// cedian.c 
// netkill /98/8/14/

inherit ROOM;

void create()
{
	set("short", "侧殿");
	set("long", @LONG
一间侧殿，堆放着些木柴，干草之内的东西。
LONG
	);

	set("exits", ([
		"west" : __DIR__"guangchang",
			]));
	
	setup();
	replace_program(ROOM);
}

