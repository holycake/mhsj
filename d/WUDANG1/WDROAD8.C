// wdroad8.c 黄土路
// netkill

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "黄土路" NOR);
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。西边是一座高山。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad7",
		"west" : __DIR__"shanmen",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 4 ]));

	setup();
	replace_program(ROOM);
}

