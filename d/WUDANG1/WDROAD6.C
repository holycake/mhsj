// wdroad6.c 黄土路
// by Xiang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "黄土路" NOR);
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖北境界，
据说经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southeast" : __DIR__"wdroad5",
		"west" : __DIR__"wdroad7",
	]));

	setup();
	replace_program(ROOM);
}

