// /d/wudang/houshan
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN "后山小路" NOR);
	set("long", @LONG
小路越走越崎岖，两旁杂草丛生，松林密布，向上看去，只见云雾缭绕，
不知武当在何处。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"wdxiaolu1",
		"southwest" : __DIR__"houshan2",
	]));
	
	setup();
        replace_program(ROOM);
	
}