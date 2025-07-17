#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的西北侧。这里有个角门，将繁华喧闹的世界隔绝在外。出去可以直
接坐船进入秦淮河。
LONG
        );
        set("exits", ([
		"south" : __DIR__"yuan_w1",
		"east" : __DIR__"yuan_n",
		"northwest" : __DIR__"yuan_door",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
