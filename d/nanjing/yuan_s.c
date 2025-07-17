#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的入口。青条石砌就的观景台架在湖水之上。往左右看去，庞大的花园
四通八达。南边是正厅和居住的区域。
LONG
        );
        set("exits", ([
//		"north" : __DIR__"yuan_ting",
		"south" : __DIR__"room_zhengting",
		"east" : __DIR__"yuan_se",
		"west" : __DIR__"yuan_sw",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
