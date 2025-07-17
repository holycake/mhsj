#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的东边，碎石铺就的小径两旁种满了各种花花草草。前方用篱笆围出
一块地方，里面放着上百盆的名贵花卉。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yuan_ne",
		"south" : __DIR__"yuan_e2",
		"west" : __DIR__"yuan_rockery",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
