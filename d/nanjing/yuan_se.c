#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的东南角，这里有块空地，绿草如荫。一棵高大的树下竟有一个秋千。
边上摆放着几个大小不一的石头，成为天然的桌椅。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yuan_e2",
		"west" : __DIR__"yuan_s",
	]));
	set("objects", ([
		__DIR__"npc/chenjing" : 1,
		__DIR__"npc/wengnanxi" : 1,
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
