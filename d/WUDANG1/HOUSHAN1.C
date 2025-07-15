// /d/wudang/houshan
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN "后山小路" NOR);
	set("long", @LONG
一条小路弯弯曲曲向下延升，不知到通向哪里。两旁杂草丛生，左边
的草有被踩过的痕迹，似乎有人常从这里过。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"houshan2",
		"southup" : __DIR__"houshan",
	]));
	
	setup();
        replace_program(ROOM);
	
}