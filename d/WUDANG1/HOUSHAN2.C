// /d/wudang/houshan
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN "后山小路" NOR);
	set("long", @LONG
小路越走越崎岖，两旁杂草丛生，松林密布，不时有一两只
野土从你的身边跑过。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"houshan3",
		"southup" : __DIR__"houshan1",
	]));
	
	setup();
        replace_program(ROOM);
	
}