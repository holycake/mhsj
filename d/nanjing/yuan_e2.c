#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的东边，碎石铺就的小径两旁种满了各种花花草草。微风从湖面吹来
，带来阵阵凉意。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yuan_e1",
		"south" : __DIR__"yuan_se",
		"west" : __DIR__"yuan_ting",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
