// huayuan.c 
// netkill /98/8/14/

inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
一个小花园，种满了各种花草，可能很没有人来打理，花虽然茂
盛，却显得杂乱无章。
LONG
	);

	set("exits", ([
		"west" : __DIR__"cedian",
			]));
	
	setup();
	replace_program(ROOM);
}

