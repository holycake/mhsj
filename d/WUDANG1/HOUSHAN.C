// /d/wudang/houshan
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN "后山" NOR);
	set("long", @LONG
你走进武当后山，只见一条小路弯弯曲曲向下延升，不知到通向哪里。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"houshan1",
		"south" : __DIR__"houmen",
	]));
	
	setup();
        replace_program(ROOM);
	
}